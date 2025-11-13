/// ### file: buffer.h
/// 
/// ### author: Prana Ron
/// 
/// ---------------------------------------------------------
/// 
/// ### brief:
/// ph buffer header
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
#ifndef PH_BUFFER_H
#define PH_BUFFER_H
#include "numeric.h"
#include "string.h"
#include "result.h"

// --------------------------------------------------------- //

/// @brief buffer byte data type
///
/// @note for binary data
typedef struct _buffer_byte_t {
    u8_t* data;
    size_t size;
    size_t capacity;
} buffer_byte_t; // _buffer_byte_t

// TODO: ph_buffer_byte_create() {}

// TODO: ph_buffer_byte_modify() {}

// TODO: ph_buffer_byte_free() {}

// --------------------------------------------------------- //

/// @brief buffer char data type
///
/// @note for text data
typedef struct _buffer_char_t {
    str_t* data;
    size_t size;
    size_t capacity;
} buffer_char_t; // _buffer_char_t

// --------------------------------------------------------- //

/// @brief buffeer data type
///
/// @note for generic data
typedef struct _buffer_data_t {
    str_t* data;
    size_t size;
    size_t capacity;
} buffer_data_t; // _buffer_data_t

#endif // PH_BUFFER_H

