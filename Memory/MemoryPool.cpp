//
// Copyright (c) 2016 by Niclas Grande. All Rights Reserved.
//

#include "MemoryPool.h"
#include "../TMP/Helper.hpp"

void MemoryPool::requestFirstPool() { expandMetaPools(); }

void *MemoryPool::getAvailableMemAddr(int size) {
  // calculate how many chunks are needed for requested memory
  int neededChunks = ROUND_MULTI_N(size, CHUNK_SIZE) / CHUNK_SIZE;
  if (neededChunks > POOL_SIZE) {
    // requested memory size is TOO BIG!
    throw MemoryPoolNotBigEnoughException();
  }

  // search all pools for enough storage
  // and return address to matching storage
  for (auto i = MetaPools.begin(); i != MetaPools.end(); ++i) {
    int matchingIndex = -1;
    int count = 0;
    int appendingFreeChunksCount = 0;

    while (count < POOL_SIZE) {
      bool bitmapEntry = i->Bitmap[count];
      if (bitmapEntry) {
        appendingFreeChunksCount += 1;
        if (appendingFreeChunksCount == neededChunks) {
          // return the address from this index
          matchingIndex = count;
          break;
        }
      } else {
        // not enough free memory appending (next to each other)
        appendingFreeChunksCount = 0;
      }

      count++;
    }

    if (matchingIndex >= 0) {
      // found! Return address
      return &(i->Pool[matchingIndex + 1 * CHUNK_SIZE]);
    }
  }

  return nullptr;
}

void MemoryPool::expandMetaPools() {
  // every pool stores "n" chunks to store objects
  char pool[POOL_SIZE * CHUNK_SIZE];
  bool bitmap[POOL_SIZE];

  MetaPool firstPool = {pool, bitmap};
  MetaPools.push_back(firstPool);
}
