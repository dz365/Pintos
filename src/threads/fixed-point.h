
#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

#include <stdint.h>

// Using a 17.14 fixed-point number representation (1 bit is used for the sign)
#define F 16384 // i.e. 2^14, 14 bits used to represent the decimal portion

#define real int32_t

 inline real to_real(int n) {
  return n * F;
}

 inline int to_int_floor(real x) {
  return x / F;
}

 inline int to_int_round(real x) {
  return x >= 0 ? (x + F / 2) / F : (x - F / 2) / F;
}

 inline real add_reals(real x, real y) {
  return x + y;
}

 inline real subtract_reals(real x, real y) {
  return x - y;
}

 inline real add_to_real(real x, int n) {
  return x + n * F;
}

 inline real subtract_from_real(real x, int n) {
  return x - n * F;
}

 inline real multiply_reals(real x, real y) {
  return (real) (((int64_t) x) * y / F);
}

 inline real multiply_to_real(real x, int n) {
  return x * n;
}

 inline real divide_reals(real x, real y) {
  return (real) (((int64_t) x) * F / y);
}

 inline real divide_to_real(real x, int n) {
  return x / n;
}

#endif