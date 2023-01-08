#pragma once

#include <Backyard/Core/Definitions.h>

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;

typedef signed char int8;
typedef signed short int16;
typedef signed int int32;
typedef signed long long int64;

typedef unsigned char byte;
typedef bool bool8;

typedef float float32;
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