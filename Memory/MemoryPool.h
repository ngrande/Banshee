//
// Copyright (c) 2016 by Niclas Grande. All Rights Reserved.
//

// The Memory Pool is used to keep track of the used memory. It also
// "pre" allocates all available memory (a specific chunk of memory) and makes
// it available to the engine to use (which will be faster because all memory
// is allocated BEFORE it is needed - at the start and not at run-time)
#ifndef MEMORY_MEMORYPOOL_H_
#define MEMORY_MEMORYPOOL_H_

// just for fun -> Meta template programming
template <typename T, T input, int n_pow> struct TO_POW_OF_TWO {
  enum {
    RESULT = (input % 2) ? input * input
                         : input * TO_POW_OF_TWO<T, input, n_pow - 1>::RESULT
  };
};

template <typename T, T input> struct TO_POW_OF_TWO<T, input, 0> {
  enum { RESULT = 1 };
};

class MemoryPool {
private:
  // int init_size = TO_POW_OF_TWO<2, 4>::RESULT;
  int test = 2;
  void doSomething();
};

#endif
