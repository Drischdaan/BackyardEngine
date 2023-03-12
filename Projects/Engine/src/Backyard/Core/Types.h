#pragma once

#include <Backyard/Core/EngineDefinitions.h>

/** \brief An unsigned integer type that is guaranteed to be 8 bits wide. */
typedef unsigned char uint8;

/** \brief An unsigned integer type that is guaranteed to be 16 bits wide. */
typedef unsigned short uint16;

/** \brief An unsigned integer type that is guaranteed to be 32 bits wide. */
typedef unsigned int uint32;

/** \brief An unsigned integer type that is guaranteed to be 64 bits wide. */
typedef unsigned long long uint64;

/** \brief A signed integer type that is guaranteed to be 8 bits wide. */
typedef signed char int8;

/** \brief A signed integer type that is guaranteed to be 16 bits wide. */
typedef signed short int16;

/** \brief A signed integer type that is guaranteed to be 32 bits wide. */
typedef signed int int32;

/** \brief A signed integer type that is guaranteed to be 64 bits wide. */
typedef signed long long int64;

/** \brief An unsigned byte type that is guaranteed to be 8 bits wide. */
typedef unsigned char byte;

/** \brief A boolean type that is guaranteed to be 8 bits wide. */
typedef bool bool8;

/** \brief A floating point type that is guaranteed to be 32 bits wide. */
typedef float float32;

/** \brief A floating point type that is guaranteed to be 64 bits wide. */
typedef double float64;

STATIC_ASSERT(sizeof(byte) == 1, "byte must be 1 byte");
STATIC_ASSERT(sizeof(bool8) == 1, "bool8 must be 1 byte");

STATIC_ASSERT(sizeof(int8) == 1, "int8 must be 1 byte");
STATIC_ASSERT(sizeof(uint16) == 2, "uint16 must be 2 bytes");
STATIC_ASSERT(sizeof(uint32) == 4, "uint32 must be 4 bytes");
STATIC_ASSERT(sizeof(uint64) == 8, "uint64 must be 8 bytes");

STATIC_ASSERT(sizeof(int8) == 1, "int8 must be 1 byte");
STATIC_ASSERT(sizeof(int16) == 2, "int16 must be 2 bytes");
STATIC_ASSERT(sizeof(int32) == 4, "int32 must be 4 bytes");
STATIC_ASSERT(sizeof(int64) == 8, "int64 must be 8 bytes");

STATIC_ASSERT(sizeof(float32) == 4, "float32 must be 4 bytes");
STATIC_ASSERT(sizeof(float64) == 8, "float64 must be 8 bytes");
