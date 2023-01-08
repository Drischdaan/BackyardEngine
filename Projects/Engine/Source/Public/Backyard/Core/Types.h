#pragma once

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

static_assert(sizeof(byte) == 1, "byte must be 1 byte");
static_assert(sizeof(bool8) == 1, "bool8 must be 1 byte");

static_assert(sizeof(int8) == 1, "int8 must be 1 byte");
static_assert(sizeof(uint16) == 2, "uint16 must be 2 bytes");
static_assert(sizeof(uint32) == 4, "uint32 must be 4 bytes");
static_assert(sizeof(uint64) == 8, "uint64 must be 8 bytes");

static_assert(sizeof(int8) == 1, "int8 must be 1 byte");
static_assert(sizeof(int16) == 2, "int16 must be 2 bytes");
static_assert(sizeof(int32) == 4, "int32 must be 4 bytes");
static_assert(sizeof(int64) == 8, "int64 must be 8 bytes");

static_assert(sizeof(float32) == 4, "float32 must be 4 bytes");
static_assert(sizeof(float64) == 8, "float64 must be 8 bytes");