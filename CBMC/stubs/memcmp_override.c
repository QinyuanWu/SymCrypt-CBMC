#ifndef __CPROVER_STRING_H_INCLUDED
#include <string.h>
#define __CPROVER_STRING_H_INCLUDED
#endif

#undef memcmp

inline int memcmp(const void *s1, const void *s2, size_t n)
{
  __CPROVER_HIDE:;
  int res=0;
  #ifdef __CPROVER_STRING_ABSTRACTION
  __CPROVER_precondition(__CPROVER_buffer_size(s1)>=n,
                         "memcmp buffer overflow of 1st argument");
  __CPROVER_precondition(__CPROVER_buffer_size(s2)>=n,
                         "memcmp buffer overflow of 2nd argument");
  #else
  __CPROVER_precondition(__CPROVER_r_ok(s1, n),
                         "memcmp region 1 readable");
  __CPROVER_precondition(__CPROVER_r_ok(s2, n),
                         "memcpy region 2 readable");

  const unsigned char *sc1=s1, *sc2=s2;
  for(; n!=0; n--)
  __CPROVER_assigns(n, res, sc1, sc2)
  __CPROVER_loop_invariant(n >= 0 && n <= __CPROVER_loop_entry(n))
  __CPROVER_loop_invariant(__CPROVER_same_object(sc1, __CPROVER_loop_entry(sc1)))
  __CPROVER_loop_invariant(__CPROVER_same_object(sc2, __CPROVER_loop_entry(sc2)))
  __CPROVER_loop_invariant(__CPROVER_POINTER_OFFSET(sc1) <= __CPROVER_loop_entry(n) && __CPROVER_POINTER_OFFSET(sc2) <= __CPROVER_loop_entry(n))
  __CPROVER_loop_invariant(sc1 - (const unsigned char*)s1 == sc2 - (const unsigned char*)s2 &&  sc1 - (const unsigned char*)s1 == __CPROVER_loop_entry(n) - n)
  __CPROVER_decreases(n)
  {
    res = (*sc1++) - (*sc2++);
    if (res != 0)
      return res;
  }
  #endif
  return res;
}