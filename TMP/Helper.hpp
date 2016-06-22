//
// Copyright (c) 2016 by Niclas Grande. All Rights Reserved.
//

#ifndef TMP_HELPER_H_
#define TMP_HELPER_H_

////////////////////////////////////////////
// Power of two template meta program
// Example: input: 2, 2 = 4; 2, 5 = 32
////////////////////////////////////////////
template <typename T> constexpr T TO_POW_OF_2(T input, int n_pow) {
  return (n_pow <= 1) ? input : (input * TO_POW_OF_2(input, n_pow - 1));
}

////////////////////////////////////////////
// Multiple of 64 template meta program
// Example: input: 1 = 64; 64 = 64;
// 120 = 128; 255 = 256; 180 = 192
////////////////////////////////////////////
template <typename T> constexpr T ROUND_MULTI_N(T input, T base) {
  return base + (base * static_cast<T>(input / base));
}

template <typename T> constexpr T ROUND_MULTI_64(T input) {
  return ROUND_MULTI_N(input, 64);
}

#endif
