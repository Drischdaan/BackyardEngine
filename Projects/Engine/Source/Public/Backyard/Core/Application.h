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

    virtual EResult Initialize() = 0;
    virtual void Shutdown() = 0;

    [[nodiscard]] FApplicationSpecification GetSpecification() const { return m_Specification; }

protected:
    FApplicationSpecification m_Specification;
    
};
