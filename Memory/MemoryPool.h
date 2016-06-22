//
// Copyright (c) 2016 by Niclas Grande. All Rights Reserved.
//

// The Memory Pool is used to keep track of the used memory. It also
// "pre" allocates all available memory (a specific chunk of memory) and makes
// it available to the engine to use (which will be faster because all memory
// is allocated BEFORE it is needed - at the start and not at run-time)
#ifndef MEMORY_MEMORYPOOL_H_
#define MEMORY_MEMORYPOOL_H_
#define SIZE_OF_POOL 1000

#include <cstddef>
#include <vector>
#include <exception>

class MemoryPoolNotBigEnoughException : public std::exception {
  virtual const char *what() const throw() {
    return "Size of memory pool was not big enough.";
  }
};

class MemoryPool {
private:
  struct MetaPool {
    char *Pool;
    // stores the bits of the pool's chunks
    // first bit is the first chunk in the pool
    // true => free
    bool *Bitmap;
  };
  const int CACHE_LINE_SIZE = 64;
  // real allocated memory = POOL_SIZE * CHUNK_SIZE  => x bytes
  const int POOL_SIZE = SIZE_OF_POOL;
  const int CHUNK_SIZE = CACHE_LINE_SIZE;
  std::vector<MetaPool> MetaPools;
  MemoryPool *pInstance;

  // request first pool etc.
  void requestFirstPool();
  // request more pools if the current pool has not enough memory free for the
  // requested object's size
  void expandMetaPools();
  // search for fitting free space and return address of this memory
  void *getAvailableMemAddr(int size);

public:
  void *allocate(std::size_t size);
  void free(void *pointer);
  MemoryPool() { requestFirstPool(); }

  // singleton
  // lazy and guaranteed to be freed
  static MemoryPool &getInstance() {
    // => statics in a function begin to live when
    // the program flow encounters the declaration
    // and ends at program termination.
    static MemoryPool instance;
    return instance;
  }

  // delete dont wanted methods
  MemoryPool(MemoryPool const &) = delete;
  void operator=(MemoryPool const &) = delete;
};

#endif
