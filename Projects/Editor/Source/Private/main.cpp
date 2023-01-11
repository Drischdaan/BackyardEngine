#include "pch.h"

#include <Backyard.h>

class FEditorApplication : public FApplication
{
public:
    explicit FEditorApplication()
        : FApplication({ "Backyard Editor" })
    {
    }

    EResult Initialize() override
    {
        return RESULT_OK;
    }
    
    void Shutdown() override
    {
    }
    
};

BACKYARD_ENGINE_ENTRY_POINT(FEditorApplication)
