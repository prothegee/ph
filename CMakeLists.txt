cmake_minimum_required(VERSION 3.25)

set(PH_VERSION_MAJOR 0)
set(PH_VERSION_MINOR 1)
set(PH_VERSION_PATCH 0)
set(PH_VERSION_RELEASE_DATE 20250612)

set(PH_FEATURES_LIST)
set(PH_C_COMPILER_NAME)

project(ph
    VERSION "${PH_VERSION_MAJOR}.${PH_VERSION_MINOR}.${PH_VERSION_PATCH}"
    DESCRIPTION "module library treatement for c project"
    HOMEPAGE_URL "https://github.com/prothegee/ph"
    LANGUAGES C
)

option(PH_BUILD_TEST "ph build test" OFF)
option(PH_BUILD_TOOL "ph build tool" OFF)

# debug stat preproc
if(NOT DEFINED PH_IS_DEBUG)
    set(PH_IS_DEBUG true)
endif()

# release build type only to disable debug
if(CMAKE_BUILD_TYPE STREQUAL "Release"
    OR
    CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
    set(PH_IS_DEBUG false)
else()
    set(PH_IS_DEBUG true)
endif()

if(NOT DEFINED CMAKE_C_STANDARD_REQUIRED)
    set(CMAKE_C_STANDARD_REQUIRED ON)
endif()

if(NOT DEFINED CMAKE_C_EXTENSIONS)
    set(CMAKE_C_EXTENSIONS OFF)
endif()

if(NOT DEFINED CMAKE_C_FLAGS)
    set(CMAKE_C_FLAGS)
endif()

if(NOT DEFINED CMAKE_C_STANDARD)
    set(CMAKE_C_STANDARD 23)
endif()
if(${CMAKE_C_STANDARD} LESS 23)
    message(FATAL_ERROR "c standard can't be less than c23")
endif()
if(${CMAKE_C_STANDARD} STRLESS 23)
    message(FATAL_ERROR "c standard can't be less than c23")
endif()

# helper preproc c++ standard if cxx flags is not found
set(PH_C_STANDARD)
set(PH_C_STANDARD_ARGS)
set(PH_C_STANDARD_ARGS "-std=c${CMAKE_C_STANDARD}")
if (MSVC) # overwrite for msvc windows
    set(PH_C_STANDARD_ARGS "/std:c${CMAKE_C_STANDARD}")
endif()
string(FIND
    "${CMAKE_C_FLAGS}"
    "${PH_C_STANDARD_ARGS}"
    PH_C_STANDARD
)
if(PH_C_STANDARD EQUAL -1)
    set(CMAKE_C_FLAGS
        "${PH_C_STANDARD_ARGS}"
    )
endif()

include(CheckIncludeFile)
include(GenerateExportHeader)
include(CMakeDependentOption)
include(CMakeFindDependencyMacro)
include(CMakePackageConfigHelpers)
include(FindPackageHandleStandardArgs)

set(PH_BUILD_SYSTEM)
set(PH_IS_LINUX false)
set(PH_IS_MACOS false)
set(PH_IS_WINDOWS false)
set(PH_IS_ANDROID false)
set(PH_IS_IOS false)

if(LINUX)
    set(PH_IS_LINUX true)
    set(PH_BUILD_SYSTEM "GNU / Linux")
    message(STATUS "build system: linux")
elseif(ANDROID)
    set(PH_IS_ANDROID true)
    set(PH_BUILD_SYSTEM "Android")
    message(STATUS "build system: android")
    message(WARNING "build system is not supported, you are on your own risk")
elseif(APPLE)
    set(PH_IS_MACOS true)
    set(PH_BUILD_SYSTEM "Apple MacOS")
    message(STATUS "build system: macos")
    message(WARNING "build system is not supported, you are on your own risk")

    if(IOS)
        set(PH_IS_IOS true)
        set(PH_BUILD_SYSTEM "Apple iOs")
    endif()
elseif(WIN32)
    set(PH_IS_WINDOWS)
    set(PH_BUILD_SYSTEM "Windows")
    message(WARNING "build system is not supported, you are on your own risk")
else()
    set(PH_BUILD_SYSTEM "UNKNOWN")
    message(AUTHOR_WARNING "build system: unknown")
    message(WARNING "build system is not supported, you are on your own risk")
endif()

if(NOT DEFINED PH_HEADER_FILES)
    set(PH_HEADER_FILES)
endif()
list(APPEND PH_HEADER_FILES
    "${CMAKE_SOURCE_DIR}/ph_function_date_and_time.h"
    "${CMAKE_SOURCE_DIR}/ph_function_utility.h"
)

if(NOT DEFINED PH_SOURCE_FILES)
    set(PH_SOURCE_FILES)
endif()
list(APPEND PH_SOURCE_FILES
    "${CMAKE_SOURCE_DIR}/ph_function_date_and_time.c"
    "${CMAKE_SOURCE_DIR}/ph_function_utility.c"
)

set(PH_OUTPUT_NAME "ph")

add_library(${PROJECT_NAME} OBJECT ${PH_SOURCE_FILES})
add_library(ph_static       STATIC $<TARGET_OBJECTS:${PROJECT_NAME}>)
add_library(ph_shared       SHARED $<TARGET_OBJECTS:${PROJECT_NAME}>)

if(NOT WIN32)
    set_target_properties(ph_static PROPERTIES
        OUTPUT_NAME "${PH_OUTPUT_NAME}"
    )
    set_target_properties(ph_shared PROPERTIES
        VERSION     "${PH_VERSION_MAJOR}.${PH_VERSION_MINOR}.${PH_VERSION_PATCH}"
        SOVERSION   "${PH_VERSION_MAJOR}.${PH_VERSION_MINOR}.${PH_VERSION_PATCH}"
        OUTPUT_NAME "${PH_OUTPUT_NAME}"
    )
else()
    set_target_properties(ph_static PROPERTIES
        ARCHIEVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
        OUTPUT_NAME "${PH_OUTPUT_NAME}"
    )
    set_target_properties(ph_shared PROPERTIES
        ARCHIEVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        OUTPUT_NAME "${PH_OUTPUT_NAME}"
    )
endif()

string(APPEND PH_FEATURES_LIST "#----------------------------------#\n")
include(package-handler.conf.cmake)

# compiler options
set(PH_GNU false)
set(PH_MSVC false)
set(PH_CLANG false)

if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wno-unused-value
        -Wno-unused-variable
        -Wno-parentheses
        -Wno-switch
        -Wno-format
        -Wno-multichar
        -Wno-char-subscripts
        -Wno-empty-body
        -Wno-unused-function
        -Wunused-parameter
        -Wno-deprecated-declarations
    )

    set(PH_C_COMPILER_NAME "GNU")
    set(PH_GNU true)
    set(PH_MSVC false)
    set(PH_CLANG false)
elseif(CMAKE_C_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE
        /W4
    )

    set(PH_C_COMPILER_NAME "MSVC")
    set(PH_GNU false)
    set(PH_MSVC true)
    set(PH_CLANG false)
elseif(CMAKE_C_COMPILER_ID MATCHES "[Cc]lang")
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wno-unused-value
        -Wno-unused-variable
        -Wno-parentheses
        -Wno-switch
        -Wno-format
        -Wno-multichar
        -Wno-char-subscripts
        -Wno-empty-body
        -Wno-unused-function
        -Wunused-parameter
        -Wno-deprecated-declarations
    )

    set(PH_C_COMPILER_NAME "CLANG")
    set(PH_GNU false)
    set(PH_MSVC false)
    set(PH_CLANG true)
else()
    message(NOTICE "-- ${PROJECT_NAME}: -DCMAKE_C_COMPILER_ID is not supported as ${CMAKE_C_COMPILER_ID}")
    set(PH_C_COMPILER_NAME "UNKNOWN")
endif()

generate_export_header(ph
    EXPORT_FILE_NAME
        ${CMAKE_SOURCE_DIR}/ph_export.h
)
generate_export_header(ph_static
    EXPORT_FILE_NAME
        ${CMAKE_SOURCE_DIR}/ph_export_static.h
)
generate_export_header(ph_shared
    EXPORT_FILE_NAME
        ${CMAKE_SOURCE_DIR}/ph_export_shared.h
)

configure_file(
    ${CMAKE_SOURCE_DIR}/ph_config.in.h
    ${CMAKE_SOURCE_DIR}/ph_config.h
)

target_compile_definitions(ph_shared PRIVATE PH_SHARED)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_SOURCE_DIR}
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
)

target_sources(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}
)

# each target
foreach(PH_TARGET ph_static ph_shared)
    if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
        target_compile_options(${PH_TARGET} PRIVATE
            -Wall
            -Wextra
            -Wpedantic
            -Wno-unused-value
            -Wno-unused-variable
            -Wno-reorder
            -Wno-parentheses
            -Wno-switch
            -Wno-format
            -Wno-invalid-offsetof
            -Wno-multichar
            -Wno-char-subscripts
            -Wno-empty-body
            -Wno-unused-function
            -Wunused-parameter
            -Wno-deprecated-declarations
        )
    elseif(CMAKE_C_COMPILER_ID STREQUAL "MSVC")
        target_compile_options(${PH_TARGET} PRIVATE
            /W4
        )
    elseif(CMAKE_C_COMPILER_ID MATCHES "[Cc]lang")
        target_compile_options(${PH_TARGET} PRIVATE
            -Wall
            -Wextra
            -Wpedantic
            -Wno-unused-value
            -Wno-unused-variable
            -Wno-reorder
            -Wno-parentheses
            -Wno-switch
            -Wno-format
            -Wno-invalid-offsetof
            -Wno-multichar
            -Wno-char-subscripts
            -Wno-empty-body
            -Wno-unused-function
            -Wunused-parameter
            -Wno-deprecated-declarations
        )
    else()
        message(NOTICE "-- ${PH_TARGET}: -DCMAKE_C_COMPILER_ID is not supported as ${CMAKE_C_COMPILER_ID}")
    endif()

    # argon2
    if(PH_ARGON2_FOUND)
        target_link_libraries(${PH_TARGET} PRIVATE argon2)
    endif()

    # curl
    if(PH_CURL_FOUND)
        target_link_libraries(${PH_TARGET} PRIVATE curl)
    endif()

    # jsoncpp
    if(PH_JSONCPP_FOUND)
        target_link_libraries(${PH_TARGET} PRIVATE jsoncpp)
    endif()

    # openssl
    if(PH_OPENSSL_FOUND)
        target_link_libraries(${PH_TARGET} PRIVATE OpenSSL::SSL OpenSSL::Crypto)
    endif()

    # python3

    # stb
    if(PH_STB_FOUND)
        target_include_directories(${PH_TARGET} PRIVATE ${PH_STB_DIR})
    endif()
endforeach()

if(PH_BUILD_TEST)
    # 
endif()

if(PH_BUILD_TOOL)
    # 
endif()

string(APPEND PH_FEATURES_LIST "#----------------------------------#\n")
string(APPEND PH_FEATURES_LIST "- Compiler             : ${CMAKE_C_COMPILER_ID}\n")
string(APPEND PH_FEATURES_LIST "- Build sys            : ${PH_BUILD_SYSTEM}\n")
string(APPEND PH_FEATURES_LIST "- Build test           : ${PH_BUILD_TEST}\n")
string(APPEND PH_FEATURES_LIST "- Build tool           : ${PH_BUILD_TOOL}\n")
string(APPEND PH_FEATURES_LIST "- CMAKE_C_FLAGS        : ${CMAKE_C_FLAGS}\n")
string(APPEND PH_FEATURES_LIST "- CMAKE_C_STANDARD     : ${CMAKE_C_STANDARD}\n")

message(NOTICE "#----------------------------------#")
message(NOTICE "      ${PROJECT_NAME} configuration status\n"
    "${PH_FEATURES_LIST}"
)

