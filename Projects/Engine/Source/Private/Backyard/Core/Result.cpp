#include "pch.h"

#include <Backyard/Core/Result.h>

#define DEFINE_RESULT_STRING(result, string) case result: return string

const char* Result::ToString(EResult result)
{
    switch (result)
    {
        // Success codes
        DEFINE_RESULT_STRING(RESULT_OK, "Ok");
        DEFINE_RESULT_STRING(RESULT_SUCCESS, "Success");

        // Generic failure codes
        DEFINE_RESULT_STRING(RESULT_FAILURE, "Failure");
        DEFINE_RESULT_STRING(RESULT_ERROR, "Error");
        DEFINE_RESULT_STRING(RESULT_INVALID, "Invalid");
        DEFINE_RESULT_STRING(RESULT_NOT_IMPLEMENTED, "Not implemented");

    case RESULT_MAX_RESULTS:
        default:
            return "Unknown Result";
    }
}

bool Result::IsSuccess(EResult result)
{
    return result == RESULT_OK || result == RESULT_SUCCESS;
}

bool Result::IsFailure(EResult result)
{
    return !IsSuccess(result);
}
