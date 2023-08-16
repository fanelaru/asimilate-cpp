#ifndef TEMPLATES-TEMPLATE-STACK_H
#define TEMPLATES-TEMPLATE-STACK_H

#include <string>
#include <vector>

class StackException : public std::exception {
    std::string msg;
public:
    StackException(const std::string& m) : msg(m) {}

    const char *what() const noexcept override {
        return msg.c_str();
    }
};

template<typename T, template<typename, typename> class C = std::vector>
class Stack {
    C<T, std::allocator<T>> data;
public:
    void push(const T& n) {
        data.push_back(n);
    }
    T top() {
        if (data.size() == 0)
            throw StackException("Empty stack");

        return data.back();
    }
    void pop() {
        if (data.size() == 0)
            throw StackException("Empty stack");

        data.pop_back();
    }
};

#endif // TEMPLATES-TEMPLATE-STACK_H