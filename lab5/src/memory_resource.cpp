#include "memory_resource.h"
#include <cstring>

FixedBlockMemoryResource::FixedBlockMemoryResource(size_t blockSize)
    : blockSize(blockSize), currentOffset(0), memoryBlock(new char[blockSize]) {}

FixedBlockMemoryResource::~FixedBlockMemoryResource() {
    delete[] memoryBlock;
}

void* FixedBlockMemoryResource::do_allocate(size_t bytes, size_t alignment) {
    if (currentOffset + bytes > blockSize) {
        throw std::bad_alloc();
    }
    void* ptr = memoryBlock + currentOffset;
    allocatedBlocks[ptr] = bytes;
    currentOffset += bytes;
    return ptr;
}

void FixedBlockMemoryResource::do_deallocate(void* p, size_t bytes, size_t alignment) {
    allocatedBlocks.erase(p);
}

bool FixedBlockMemoryResource::do_is_equal(const std::pmr::memory_resource& other) const noexcept {
    return this == &other;
}
