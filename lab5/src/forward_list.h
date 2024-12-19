#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <memory>
#include <memory_resource>
#include <iterator>
#include <stdexcept>

template <typename T>
class ForwardList {
public:
    using value_type = T;
    using allocator_type = std::pmr::polymorphic_allocator<T>;
    using iterator = typename std::forward_list<T, allocator_type>::iterator;
    using const_iterator = typename std::forward_list<T, allocator_type>::const_iterator;

    ForwardList(std::pmr::memory_resource* mr = std::pmr::get_default_resource());
    ~FowardList();

    iterator begin() noexcept;
    iterator end() noexcept;
    const_iterator begin() const noexcept;
    const_iterator end() const noexcept;

    void push_front(const T& value);
    void pop_front();
    bool empty() const noexcept;

private:
    std::forward_list<T, allocator_type> list;
    std::pmr::memory_resource* memoryResource;
};

#endif 
