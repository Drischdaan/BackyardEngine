#pragma once

#include <Backyard/Core/EngineDefinitions.h>
#include <type_traits>
#include <new>

enum API EMemoryTag
{
    MEMORY_TAG_UNKNOWN = 0,
    MEMORY_TAG_CORE = 1,
    MEMORY_TAG_RENDERER = 2,
    
    MEMORY_TAG_MAX_TAGS,
};

struct API FMemoryStatistics
{
    uint32 TotalAllocations = 0;
    uint32 TotalFrees = 0;
    uint32 AllocatedMemory = 0;

    uint32 AllocatedMemoryByTag[MEMORY_TAG_MAX_TAGS] = { 0 };
};

class API FAllocator
{
public:
    virtual ~FAllocator() = default;

    virtual void* AllocateMemory(size_t size, EMemoryTag tag = MEMORY_TAG_UNKNOWN) = 0;
    virtual void FreeMemory(void* memory, size_t size, EMemoryTag tag = MEMORY_TAG_UNKNOWN) = 0;

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
            // ReSharper disable once CppCStyleCast
            FreeMemory((void*)object, sizeof(T));
        }
    }

    [[nodiscard]] FMemoryStatistics& GetStatistics() { return m_Statistics; }

protected:
    void AddToTag(EMemoryTag tag, size_t size)
    {
        m_Statistics.TotalAllocations++;
        m_Statistics.AllocatedMemory += static_cast<uint32>(size);
        m_Statistics.AllocatedMemoryByTag[tag] += static_cast<uint32>(size);
    }
    
    void RemoveFromTag(EMemoryTag tag, size_t size)
    {
        m_Statistics.TotalFrees++;
        m_Statistics.AllocatedMemory -= static_cast<uint32>(size);
        m_Statistics.AllocatedMemoryByTag[tag] -= static_cast<uint32>(size);
    }

private:
    FMemoryStatistics m_Statistics;
    
};
