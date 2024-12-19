#include <iostream>
#include "memory_resource.h"
#include "forward_list.h"

int main() {
    FixedBlockMemoryResource memoryResource(1024);
    ForwardList<int> intList(&memoryResource);

    intList.push_front(1);
    intList.push_front(2);
    intList.push_front(3);

    std::cout << "Forward List: ";
    for (auto it = intList.begin(); it != intList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    struct ComplexType {
        int a;
        double b;
    };

    ForwardList<ComplexType> complexList(&memoryResource);
    complexList.push_front({1, 2.5});
    complexList.push_front({2, 3.5});
    complexList.push_front({3, 4.5});

    std::cout << "Complex Forward List: ";
    for (auto it = complexList.begin(); it != complexList.end(); ++it) {
        std::cout << "(" << it->a << ", " << it->b << ") ";
    }
    std::cout << std::endl;

    return 0;
}
