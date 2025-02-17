#ifndef COMPLEX_H
#define COMPLEX_H

#include <math.h>
#include "type.h"

// NOTE: Just a basic Complex Number implementation

typedef struct c32_s c32_t;
typedef struct c64_s c64_t;

// INFO: for SIMD

typedef struct c32x2_s  c32x2_t;
typedef struct c32x4_s  c32x4_t;
typedef struct c32x8_s  c32x8_t;
typedef struct c32x16_s c32x16_t;

typedef struct c32x2_s  c32x2_t;
typedef struct c32x4_s  c32x4_t;
typedef struct c32x8_s  c32x8_t;
typedef struct c32x16_s c32x16_t;

//------------------------------------------------------------------------------
// Complex float 32
//------------------------------------------------------------------------------

// 32 Bits
struct c32_s {
  f32_t re;
  f32_t im;
};

//------------------------------------------------------------------------------
// Complex float 64
//------------------------------------------------------------------------------

// 64 Bits
struct c64_s {
  f64_t re;
  f64_t im;
};

//------------------------------------------------------------------------------
// Complex float 32 SIMD
//------------------------------------------------------------------------------

// 64 Bits
struct c32x2_s {
  f32_t re[2];
  f32_t im[2];
};

// 128 Bits
struct c32x4_s {
  f32_t re[4];
  f32_t im[4];
};

// 256 Bits
struct c32x8_s {
  f32_t re[8];
  f32_t im[8];
};

// 512 Bits
struct c32x16_s {
  f32_t re[16];
  f32_t im[16];
};

//------------------------------------------------------------------------------
// Complex float 64 SIMD
//------------------------------------------------------------------------------

// 128 Bits
struct c64x2_s {
  f64_t re[2];
  f64_t im[2];
};

// 256 Bits
struct c64x4_s {
  f64_t re[4];
  f64_t im[4];
};

// 512 Bits
struct c64x8_s {
  f64_t re[8];
  f64_t im[8];
};

// 1024 Bits
struct c64x16_s {
  f64_t re[16];
  f64_t im[16];
};

//------------------------------------------------------------------------------
// Absolute - [type]_abs(z)
//------------------------------------------------------------------------------

static __inline__ f32_t c32_abs(c32_t z) {
  return sqrtf((z.re * z.re) + (z.im * z.im));
}

static __inline__ f64_t c64_abs(c64_t z) {
  return sqrt((z.re * z.re) + (z.im * z.im));
}

//------------------------------------------------------------------------------
// Absolute power 2 - [type]_abs_2(z)
//------------------------------------------------------------------------------

static __inline__ f32_t c32_abs_2(c32_t z) {
  return (z.re * z.re) + (z.im * z.im);
}

static __inline__ f64_t c64_abs_2(c64_t z) {
  return (z.re * z.re) + (z.im * z.im);
}

//------------------------------------------------------------------------------
// Argument - [type]_arg(z)
//------------------------------------------------------------------------------

static __inline__ f32_t c32_arg(c32_t z) {
  return atan2f(z.im, z.re);
}

static __inline__ f64_t c64_arg(c64_t z) {
  return atan2(z.im, z.re);
}

//------------------------------------------------------------------------------
// Addition - [type]_add(z, w)
//------------------------------------------------------------------------------

static __inline__ c32_t c32_add(c32_t z, c32_t w) {
  return (c32_t){
    .re = z.re + w.re,
    .im = z.im + w.im
  };
}

static __inline__ c64_t c64_add(c64_t z, c64_t w) {
  return (c64_t){
    .re = z.re + w.re,
    .im = z.im + w.im
  };
}

//------------------------------------------------------------------------------
// Division - [type]_div(z, w)
//------------------------------------------------------------------------------

static __inline__ c32_t c32_div(c32_t z, c32_t w) {
  const f32_t abs_2 = (w.re * w.re) + (w.im * w.im);

  return (c32_t){
    .re = ((z.re * w.re) + (z.im * w.im)) / abs_2,
    .im = ((z.im * w.re) - (z.re * w.im)) / abs_2
  };
}

static __inline__ c64_t c64_div(c64_t z, c64_t w) {
  const f64_t abs_2 = (w.re * w.re) + (w.im * w.im);

  return (c64_t){
    .re = ((z.re * w.re) + (z.im * w.im)) / abs_2,
    .im = ((z.im * w.re) - (z.re * w.im)) / abs_2
  };
}

//------------------------------------------------------------------------------
// Exponential - [type]_e(z)
//------------------------------------------------------------------------------

static __inline__ c32_t c32_e(c32_t z) {
  (void)z;
  return (c32_t){
    .re = 0,
    .im = 0
  };
}

static __inline__ c64_t c64_e(c64_t z) {
  (void)z;
  return (c64_t){
    .re = 0,
    .im = 0
  };
}

//------------------------------------------------------------------------------
// Logarithm Natural - [type]_ln(z)
//------------------------------------------------------------------------------

static __inline__ c32_t c32_ln(c32_t z) {
  (void)z;
  return (c32_t){
    .re = 0,
    .im = 0
  };
} 

static __inline__ c64_t c64_ln(c64_t z) {
  (void)z;
  return (c64_t){
    .re = 0,
    .im = 0
  };
}

//------------------------------------------------------------------------------
// Multiplication - [type]_mul(z, w)
//------------------------------------------------------------------------------

static __inline__ c32_t c32_mul(c32_t z, c32_t w) {
  return (c32_t){
    .re = (z.re * w.re) - (z.im * w.im),
    .im = (z.re * w.im) + (z.im * w.re)
  };
}

static __inline__ c64_t c64_mul(c64_t z, c64_t w) {
  return (c64_t){
    .re = (z.re * w.re) - (z.im * w.im),
    .im = (z.re * w.im) + (z.im * w.re)
  };
}

//------------------------------------------------------------------------------
// Power - [type]_pow(z, n)
//------------------------------------------------------------------------------

static __inline__ c32_t c32_pow(c32_t z, f32_t n) {
  const f32_t r = c32_abs(z);
  const f32_t phi = c32_arg(z);
  const f32_t r_n = powf(r, n);
  const f32_t n_phi = n * phi;

  return (c32_t){
    .re = r_n * cosf(n_phi),
    .im = r_n * sinf(n_phi)
  };
}

static __inline__ c64_t c64_pow(c64_t z, f64_t n) {
  const f64_t r = c64_abs(z);
  const f64_t phi = c64_arg(z);
  const f64_t r_n = pow(r, n);
  const f64_t n_phi = n * phi;

  return (c64_t){
    .re = r_n * cos(n_phi),
    .im = r_n * sin(n_phi)
  };
}

//------------------------------------------------------------------------------
// Power Complex - [type]_pow_c(z, w)
//------------------------------------------------------------------------------

static __inline__ c32_t c32_pow_c(c32_t z, c32_t w) {
  return c32_e(c32_mul(w, c32_ln(z)));
}

static __inline__ c64_t c64_pow_c(c64_t z, c64_t w) {
  return c64_e(c64_mul(w, c64_ln(z)));
}

//------------------------------------------------------------------------------
// Substraction - [type]_sub(z, w)
//------------------------------------------------------------------------------

static __inline__ c32_t c32_sub(c32_t z, c32_t w) {
  return (c32_t){
    .re = z.re - w.re,
    .im = z.im - w.im
  };
}

static __inline__ c64_t c64_sub(c64_t z, c64_t w) {
  return (c64_t){
    .re = z.re - w.re,
    .im = z.im - w.im
  };
}

//------------------------------------------------------------------------------
// SIMD
//------------------------------------------------------------------------------

// Format - Array of Structures (AoS)
// Format - Structure of Arrays (SoA)

// For this Function
//static __inline__ c32x2_t c32_to_c32x2(c32_t *z) {
//  return (c32x2_t){
//    .re = { z[0].re, z[1].re },
//    .im = { z[0].im, z[1].im }
//  };
//}

#include <arm_neon.h>

//------------------------------------------------------------------------------
// SIMD - Addition - [type]_add(z, w)
//------------------------------------------------------------------------------

static __inline__ void c32x2_add(c32x2_t* z, c32x2_t* w, c32x2_t* r) {
  const float32x2_t z_re = vld1_f32(z->re);
  const float32x2_t z_im = vld1_f32(z->im);
  const float32x2_t w_re = vld1_f32(w->re);
  const float32x2_t w_im = vld1_f32(w->im);

  vst1_f32(r->re, vadd_f32(z_re, w_re));
  vst1_f32(r->im, vadd_f32(z_im, w_im));
}

static __inline__ void c32x4_add(c32x4_t* z, c32x4_t* w, c32x4_t* r) {
  const float32x4_t z_re = vld1q_f32(z->re);
  const float32x4_t z_im = vld1q_f32(z->im);
  const float32x4_t w_re = vld1q_f32(w->re);
  const float32x4_t w_im = vld1q_f32(w->im);

  vst1q_f32(r->re, vaddq_f32(z_re, w_re));
  vst1q_f32(r->im, vaddq_f32(z_im, w_im));
}

static __inline__ void c32x8_add(c32x8_t* z, c32x8_t* w, c32x8_t* r) {
  float32x4_t z_re;
  float32x4_t z_im;
  float32x4_t w_re;
  float32x4_t w_im;

  // First Half
  z_re = vld1q_f32(z->re);
  z_im = vld1q_f32(z->im);
  w_re = vld1q_f32(w->re);
  w_im = vld1q_f32(w->im);
  vst1q_f32(r->re, vaddq_f32(z_re, w_re));
  vst1q_f32(r->im, vaddq_f32(z_im, w_im));
  // Second Half
  z_re = vld1q_f32(&z->re[4]);
  z_im = vld1q_f32(&z->im[4]);
  w_re = vld1q_f32(&w->re[4]);
  w_im = vld1q_f32(&w->im[4]);
  vst1q_f32(&r->re[4], vaddq_f32(z_re, w_re));
  vst1q_f32(&r->im[4], vaddq_f32(z_im, w_im));
}

// static __inline__ void c32x16_add(c32x16_t* z, c32x16_t* w, c32x16_t* r) {}

//------------------------------------------------------------------------------
// SIMD - Multiplication - [type]_mul(z, w)
//------------------------------------------------------------------------------

static __inline__ void c32x2_mul(c32x2_t* z, c32x2_t* w, c32x2_t* r) {
  const float32x2_t z_re = vld1_f32(z->re);
  const float32x2_t z_im = vld1_f32(z->im);
  const float32x2_t w_re = vld1_f32(w->re);
  const float32x2_t w_im = vld1_f32(w->im);

  vst1_f32(r->re, vsub_f32(vmul_f32(z_re, w_re), vmul_f32(z_im, w_im)));
  vst1_f32(r->im, vadd_f32(vmul_f32(z_re, w_im), vmul_f32(z_im, w_re)));
}

static __inline__ void c32x4_mul(c32x4_t* z, c32x4_t* w, c32x4_t* r) {
  const float32x4_t z_re = vld1q_f32(z->re);
  const float32x4_t z_im = vld1q_f32(z->im);
  const float32x4_t w_re = vld1q_f32(w->re);
  const float32x4_t w_im = vld1q_f32(w->im);

  vst1q_f32(r->re, vsubq_f32(vmulq_f32(z_re, w_re), vmulq_f32(z_im, w_im)));
  vst1q_f32(r->im, vaddq_f32(vmulq_f32(z_re, w_im), vmulq_f32(z_im, w_re)));
}

static __inline__ void c32x8_mul(c32x8_t* z, c32x8_t* w, c32x8_t* r) {
  float32x4_t z_re;
  float32x4_t z_im;
  float32x4_t w_re;
  float32x4_t w_im;

  // First Half
  z_re = vld1q_f32(z->re);
  z_im = vld1q_f32(z->im);
  w_re = vld1q_f32(w->re);
  w_im = vld1q_f32(w->im);
  vst1q_f32(r->re, vsubq_f32(vmulq_f32(z_re, w_re), vmulq_f32(z_im, w_im)));
  vst1q_f32(r->im, vaddq_f32(vmulq_f32(z_re, w_im), vmulq_f32(z_im, w_re)));
  // Second Half
  z_re = vld1q_f32(&z->re[4]);
  z_im = vld1q_f32(&z->im[4]);
  w_re = vld1q_f32(&w->re[4]);
  w_im = vld1q_f32(&w->im[4]);
  vst1q_f32(&r->re[4], vsubq_f32(vmulq_f32(z_re, w_re), vmulq_f32(z_im, w_im)));
  vst1q_f32(&r->im[4], vaddq_f32(vmulq_f32(z_re, w_im), vmulq_f32(z_im, w_re)));
}

// static __inline__ void c32x16_mul(c32x16_t* z, c32x16_t* w, c32x16_t* r) {}

#endif
