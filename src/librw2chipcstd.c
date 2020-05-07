#if HAVE_CONFIG_H
#include <config.h>
#endif

#include <restart.h>

#include <rw2chipcstd.h>

typedef struct {
   childcb_t      childcb;
   void *restrict cargs;
} cargs_t;
 
__attribute__ ((warn_unused_result))
static int mychildcb (fd_t rd, fd_t wr, void *restrict args) {
   cargs_t *restrict cargs      = args;
   childcb_t         childcb    = cargs->childcb;
   void    *restrict child_args = cargs->cargs;
   int err;

   error_check (r_dup2 (rd,  STDIN_FILENO ) == -1) {
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunused-result"
      r_close (rd);
      r_close (wr);
	#pragma GCC diagnostic pop
      return -2;
   }
   error_check (r_dup2 (wr, STDOUT_FILENO) == -1) {
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunused-result"
      r_close (rd);
      r_close (wr);
	#pragma GCC diagnostic pop
      return -3;
   }

   /* Close fds not required by child. Also, we don't
   want the exec'ed program to know these existed */
   err  = r_close (rd);
   err |= r_close (wr);
   error_check (err != 0) { return err; }
 
   /*execv (argv[0], argv);
   return -1;*/
   return childcb (child_args);
}

/*
__attribute__ ((warn_unused_result))
static int myparentcb (pid_t cpid, fd_t rd, fd_t wr, void *restrict args) {
   char buffer[100];
   int count;
 
   /* Write to child’s stdin * /
   write (wr, "2^32\n", 5);
 
   /* Read from child’s stdout * /
   count = read (rd, buffer, sizeof (buffer) - 1);
   if (count >= 0) {
   buffer[count] = 0;
   printf("%s", buffer);
   } else {
   printf("IO Error\n");
   }
}
*/

__attribute__ ((nonnull (1, 3), warn_unused_result))
int rw2chipcstd (childcb_t childcb, void *restrict cargs, rwparentcb_t parentcb, void *restrict pargs) {
   cargs_t child_args;
   child_args.childcb = childcb;
   child_args.cargs   = cargs;
   return rw2chipc (mychildcb, &child_args, parentcb, pargs);
}

