#include "forward_list.h"

template <typename T>
FowardList<T>::FowardList(std::pmr::memory_resource* mr)
    : list(allocator_type(mr)), memoryResource(mr) {}

template <typename T>
FowardList<T>::~FowardList() {
    list.clear();
}

template <typename T>
typename ForwardList<T>::iterator ForwardList<T>::begin() noexcept {
    return list.begin();
}

template <typename T>
typename ForwardList<T>::iterator ForwardList<T>::end() noexcept {
    return list.end();
}

template <typename T>
typename ForwardList<T>::const_iterator ForwardList<T>::begin() const noexcept {
    return list.begin();
}

template <typename T>
typename ForwardList<T>::const_iterator ForwardList<T>::end() const noexcept {
    return list.end();
}

template <typename T>
void ForwardList<T>::push_front(const T& value) {
    list.push_front(value);
}

template <typename T>
void ForwardList<T>::pop_front() {
    list.pop_front();
}

template <typename T>
bool ForwardList<T>::empty() const noexcept {
    return list.empty();
}

template class ForwardList<int>;
template class ForwardList<double>;
