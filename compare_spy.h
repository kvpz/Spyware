#ifndef COMPARE_SPY_H
#define COMPARE_SPY_H

namespace fsu
{
  template < typename T >
  class LessThanSpy;

  template < typename T >
  class LessThanSpy
  {
  public:
    LessThanSpy() : counter(0)
    {}
    
    bool operator() ( const T& t1 ,const T& t2 )
    {
      counter += 1;
      return t1 < t2;
    }
    void Reset()
    {
      counter = 0;
    }

    size_t Count() const
    {
      return counter;
    }
    
  private:
    size_t counter;    
  };

}
#endif
