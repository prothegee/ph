/// ### file: ph_buffer.h
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
/// - (c) 2025 Prana Ron // @prothegee // prothegee@proton.me
/// 
/// ### contributors:
/// 
/// - Prana Ron // @prothegee // prothegee@proton.me
/// 
#ifndef PH_BUFFER_H
#define PH_BUFFER_H
#include "ph_numeric.h"
#include "ph_string.h"
#include "ph_result.h"

// --------------------------------------------------------- //

/// @brief buffer byte data type
///
/// @note for binary data
typedef struct _buffer_byte_t {
    ui8_t* data;
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
    char_t* data;
    size_t size;
    size_t capacity;
} buffer_char_t; // _buffer_char_t

// --------------------------------------------------------- //

/// @brief buffeer data type
///
/// @note for generic data
typedef struct _buffer_data_t {
    uchar_t* data;
    size_t size;
    size_t capacity;
} buffer_data_t; // _buffer_data_t

#endif // PH_BUFFER_H

