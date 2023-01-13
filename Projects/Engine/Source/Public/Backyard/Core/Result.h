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
#ifdef _BACKYARD_CONFIGURATION_DEBUG
    /**
     * @brief Converts the given result code to a string.
     * @param result The result code to convert
     * @return Result code as a string
     */
    const char* ToString(EResult result);
#endif
    
    /**
     * @brief Checks if the given result code is a success code.
     * @param result The result code to check
     * @return True if the result code is a success code, false otherwise
     */
    bool IsSuccess(EResult result);

    /**
     * @brief Checks if the given result code is a failure code.
     * @param result The result code to check
     * @return True if the result code is a failure code, false otherwise
     */
    bool IsFailure(EResult result);
}

#define IS_SUCCESS(result) (Result::IsSuccess(result))
#define IS_FAILURE(result) (Result::IsFailure(result))

#ifdef _BACKYARD_CONFIGURATION_DEBUG
    #define RESULT_TO_STRING(result) (Result::ToString(result))
#else
    #define RESULT_TO_STRING(result) ("")
#endif