/// ### file: string.h
/// 
/// ### author: Prana Ron
/// 
/// ---------------------------------------------------------
/// 
/// ### brief:
/// ph string header
/// 
/// ### note:
/// n/a
/// 
/// ---------------------------------------------------------
/// 
/// ### copyright:
/// 
/// - (c) Prana Ron // @prothegee // prothegee@proton.me
/// 
/// ### contributors:
/// 
/// - Prana Ron // @prothegee // prothegee@proton.me
/// 
#ifndef PH_STRING_H
#define PH_STRING_H
#include "size.h"

#include <string.h>

// --------------------------------------------------------- //

typedef char str_t;

/// fixed 8 size char string
typedef str_t str8_t[PH_SIZE_8_WIDTH];

/// fixed 16 size char string
typedef str_t str16_t[PH_SIZE_16_WIDTH];

/// fixed 32 size char string
typedef str_t str32_t[PH_SIZE_32_WIDTH];

/// fixed 36 size char string
typedef str_t str36_t[PH_SIZE_36_WIDTH];

/// fixed 64 size char string
typedef str_t str64_t[PH_SIZE_64_WIDTH];

/// fixed 128 size char string
typedef str_t str128_t[PH_SIZE_128_WIDTH];

// --------------------------------------------------------- //

typedef unsigned char ustr_t;

/// fixed 8 size unsigned char string
typedef ustr_t ustr8_t[PH_SIZE_8_WIDTH];

/// fixed 16 size unsigned char string
typedef ustr_t ustr16_t[PH_SIZE_16_WIDTH];

/// fixed 32 size unsigned char string
typedef ustr_t ustr32_t[PH_SIZE_32_WIDTH];

/// fixed 36 size unsigned char string
typedef ustr_t ustr36_t[PH_SIZE_36_WIDTH];

/// fixed 64 size unsigned char string
typedef ustr_t ustr64_t[PH_SIZE_64_WIDTH];

/// fixed 128 size unsigned char string
typedef ustr_t ustr128_t[PH_SIZE_128_WIDTH];

// --------------------------------------------------------- //

#endif // PH_STRING_H

