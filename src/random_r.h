/* random_r() is a glibc extension */

#include <stdint.h>
#include <stdlib.h>

#ifndef __GLIBC__

#ifdef __cplusplus
extern "C" {
#endif

#define __NEED_TO_DEFINE_RANDOM_R__ 1

struct random_data
  {
    int32_t *fptr;		/* Front pointer.  */
    int32_t *rptr;		/* Rear pointer.  */
    int32_t *state;		/* Array of state values.  */
    int rand_type;		/* Type of random number generator.  */
    int rand_deg;		/* Degree of random number generator.  */
    int rand_sep;		/* Distance between front and rear.  */
    int32_t *end_ptr;		/* Pointer behind state table.  */
  };

extern int random_r (struct random_data *__buf,
		     int32_t *__result);

extern int srandom_r (unsigned int __seed, struct random_data *__buf);

extern int initstate_r (unsigned int __seed, char *__statebuf,
			size_t __statelen,
			struct random_data *__buf);

extern int setstate_r (char *__statebuf,
		       struct random_data *__buf);

#ifdef __cplusplus
}
#endif

#endif
