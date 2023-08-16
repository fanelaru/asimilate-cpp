#include <iostream>
#include <vector>

#include "templates-stack-static.h"

// Function template
template<typename T>
const T& max(const T& a, const T& b) {
    std::cout << "Plain template" << std::endl;
    return (a>b) ? a : b;
}

// Overload for 3 parameters
template<typename T>
const T& max(const T& a, const T& b, const T& c) {
    std::cout << "Overload template" << std::endl;
    T tmp = (a>b) ? a : b;
    return (tmp > c) ? tmp : c;
}

// Overload for pointers
template<typename T>
const T* max(const T* a, const T* b) {
    std::cout << "Pointer template" << std::endl;
    return (*a > *b) ? a : b;
}

int main() {
    Stack<int, 20> s20i;
    Stack<float, 10> s10f;
    Stack<double, 10> s10d;
    // Stack<std::vector, 5> s5v;

    auto x = max<double>(1.2, 7.4, 5);
    std::cout << "max de 3 = " << x << std::endl;

    s20i.push(1);
    s20i.push(2);
    s20i.push(3);

    std::cout << s20i.top() << std::endl;
    s20i.pop();
    std::cout << s20i.top() << std::endl;
}