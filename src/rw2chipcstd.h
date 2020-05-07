#ifndef _RW2CHIPCSTD_H_
#define _RW2CHIPCSTD_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <rw2chipc.h>

int rw2chipcstd (
	childcb_t    childcb,  void *restrict childcb_args,
	rwparentcb_t parentcb, void *restrict parentcb_args)
__attribute__ ((nonnull (1, 3), warn_unused_result)) ;

#ifdef __cplusplus
}
#endif

#endif /* _RW2CHIPCSTD_H_ */
