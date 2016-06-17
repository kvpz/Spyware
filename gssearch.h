#ifndef _GSSEARCH_H_
#define _GSSEARCH_H_
#include <iostream>

/*
  g_lower_bound() and g_upper_bound() are generic algorithms(can be implemented
  with different containers) operating with forward iterators. A precondition
  for successful operation of each requires the range to which they are applied
  be sorted using a predicate (found in compare_spy.h).  
  They define the interval of iterators pointing to elements equal to t in the
  range: for each i in [LB,UB), *i = t.
  Note that lower bound and upper bound are the same thing when the search value
  is not in the range: "*i <= t" and "*i < t" are the same constraint when "*i
  == t" is not possible.
*/

namespace seq
{
  template <class I, typename T, class P>
  I g_lower_bound(I beg, I end, const T& t, P& cmp)
  /*
    Returns the lower bound of t in the range [beg, end). Predicate p determines order.
   */
  {
    //finding the lowest value sequentially
    for( ; beg != end; ++beg)
      if(!cmp(*beg,t))
        return beg;
    return beg;
  }

  template <class I, typename T, class P>
  I g_upper_bound(I beg, I end, const T& t, P& cmp)
  /*
    Returns the upper bound of t in the range [beg, end). Predicate p determines order.
   */
  {
    I low = beg;
    for( ; beg != end; ++beg)
      if(!cmp(*beg, t+1))
        return beg;
    return beg;
  }
  
}//namespace seq

#endif
