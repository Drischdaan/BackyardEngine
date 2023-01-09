#pragma once

enum EResult
{
    // Success codes
    RESULT_OK = 0,
    RESULT_SUCCESS = 1,

    // Generic failure codes
    RESULT_FAILURE = 2,
    RESULT_ERROR = 3,
    RESULT_INVALID = 4,
    RESULT_NOT_IMPLEMENTED = 5,
    
    RESULT_MAX_RESULTS,
};

namespace Result
{
    const char* ToString(EResult result);
    bool IsSuccess(EResult result);
    bool IsFailure(EResult result);
}

#define IS_SUCCESS(result) (Result::IsSuccess(result))
#define IS_FAILURE(result) (Result::IsFailure(result))