#ifndef MEMORY_RESOURCE_H
#define MEMORY_RESOURCE_H

#include <memory_resource>
#include <map>
#include <stdexcept>

class FixedBlockMemoryResource : public std::pmr::memory_resource {
public:
    FixedBlockMemoryResource(size_t blockSize);
    ~FixedBlockMemoryResource();

    void* do_allocate(size_t bytes, size_t alignment) override;
    void do_deallocate(void* p, size_t bytes, size_t alignment) override;
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override;

private:
    std::map<void*, size_t> allocatedBlocks;
    size_t blockSize;
    size_t currentOffset;
    char* memoryBlock;
};

#endif 
