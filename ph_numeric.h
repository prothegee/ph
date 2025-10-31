/// ### file: ph_numeric.h
/// 
/// ### author: Prana Ron
/// 
/// ---------------------------------------------------------
/// 
/// ### brief:
/// ph numeric header
/// 
/// ### note:
/// n/a
/// 
/// ---------------------------------------------------------
/// 
/// ### copyright:
/// 
/// - (c) 2025 Prana Ron // @prothegee // prothegee@proton.me
/// 
/// ### contributors:
/// 
/// - Prana Ron // @prothegee // prothegee@proton.me
/// 
#ifndef PH_NUMERIC_H
#define PH_NUMERIC_H
#include <stdint.h>
#include <stddef.h>

typedef int8_t  i8_t;
typedef int16_t i16_t;
typedef int32_t i32_t;
typedef int64_t i64_t;

typedef uint8_t  ui8_t;
typedef uint16_t ui16_t;
typedef uint32_t ui32_t;
typedef uint64_t ui64_t;

typedef float  f32_t;
typedef double f64_t;

enum bool_t : i8_t {
    false_t = 0, true_t = 1
}; // bool_t

#endif // PH_NUMERIC_H

