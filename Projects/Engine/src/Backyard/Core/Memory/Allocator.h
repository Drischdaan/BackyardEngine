#pragma once

#include <Backyard/Core/EngineDefinitions.h>

#include <Backyard/Core/Memory/Memory.h>
#include <type_traits>
#include <new>

class API IAllocator
{
public:
    virtual ~IAllocator() = default;

    virtual void* AllocateMemory(size_t size, EMemoryTag tag = MEMORY_TAG_UNKNOWN) = 0;
    virtual void FreeMemory(void* memory, size_t size, EMemoryTag tag = MEMORY_TAG_UNKNOWN) = 0;

    virtual FMemoryStatistics& GetMemoryStatistics() = 0;

public:
    template<typename T>
    T* AllocateMemory(uint32 count = 1)
    {
        return static_cast<T*>(AllocateMemory(sizeof(T) * count));
    }

    template<typename T, typename = std::enable_if_t<std::is_default_constructible_v<T>>>
    T* NewObject(EMemoryTag tag = MEMORY_TAG_UNKNOWN)
    {
        T* pointer = AllocateMemory<T>(tag);
        if(pointer)
            new (pointer) T();
        return pointer;
    }

    template<typename T, typename Arg, typename = std::enable_if_t<std::is_constructible_v<T, Arg>>>
    T* NewObject(Arg arg, EMemoryTag tag = MEMORY_TAG_UNKNOWN)
    {
        T* pointer = AllocateMemory<T>(tag);
        if(pointer)
            new (pointer) T(arg);
        return pointer;
    }

    template<typename T, typename... Args, typename = std::enable_if_t<std::is_constructible_v<T, Args>>>
    T* NewObject(EMemoryTag tag, Args... args)
    {
        T* pointer = AllocateMemory<T>(tag);
        if(pointer)
            new (pointer) T(args...);
        return pointer;
    }

    template<typename T>
    void DeleteObject(T* object, EMemoryTag tag = MEMORY_TAG_UNKNOWN)
    {
        if(object)
        {
            object->~T();
            // ReSharper disable once CppCStyleCast
            FreeMemory((void*)object, sizeof(T), tag);
        }
    }
    
private:
    
};
