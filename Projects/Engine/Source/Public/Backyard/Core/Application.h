#pragma once

#include <Backyard/Core/Result.h>

struct FApplicationSpecification
{
    const char* Name;
};

class FApplication
{
public:
    FApplication(const FApplicationSpecification& Specification)
        : m_Specification(Specification) {}
    virtual ~FApplication() = default;

    /**
     * @brief Called when the application is initialized.
     * @return Returns a result code indicating the success of the initialization.
     */
    virtual EResult Initialize() = 0;

    /**
     * @brief Called when the application is shut down.
     */
    virtual void Shutdown() = 0;

    /**
     * @brief Returns the application specification.
     * @return The application specification.
     */
    [[nodiscard]] FApplicationSpecification GetSpecification() const { return m_Specification; }

protected:
    /** The application specification containing information like name and version */
    FApplicationSpecification m_Specification;
    
};
