#pragma once

#include <Backyard/Core/EngineDefinitions.h>
#include <type_traits>
#include <new>

class API FAllocator
{
public:
    virtual ~FAllocator() = default;

    virtual void* AllocateMemory(size_t size) = 0;
    virtual void FreeMemory(void* memory) = 0;

    template<typename T>
    T* AllocateMemory(uint32 count = 1)
    {
        return static_cast<T*>(AllocateMemory(sizeof(T) * count));
    }

    template<typename T, typename = std::enable_if_t<std::is_default_constructible_v<T>>>
    T* NewObject()
    {
        T* pointer = AllocateMemory<T>();
        if(pointer)
            new (pointer) T();
        return pointer;
    }

    template<typename T, typename Arg, typename = std::enable_if_t<std::is_constructible_v<T, Arg>>>
    T* NewObject(Arg arg)
    {
        T* pointer = AllocateMemory<T>();
        if(pointer)
            new (pointer) T(arg);
        return pointer;
    }

    template<typename T, typename... Args, typename = std::enable_if_t<std::is_constructible_v<T, Args>>>
    T* NewObject(Args... args)
    {
        T* pointer = AllocateMemory<T>();
        if(pointer)
            new (pointer) T(args...);
        return pointer;
    }

    template<typename T>
    void DeleteObject(T* object)
    {
        if(object)
        {
            object->~T();
            FreeMemory(object);
        }
    }
    
};
