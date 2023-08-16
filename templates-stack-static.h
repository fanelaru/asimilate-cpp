#ifndef STACK_H
#define STACK_H

#include <string>

class StackException : public std::exception {
    std::string msg;
public:
    StackException(const std::string& m) : msg(m) {}

    const char *what() const noexcept override {
        return msg.c_str();
    }
};

template<typename T, int SIZE>
class Stack {
    T data[SIZE];
    size_t current;
public:
    Stack() : current{0} {}
    ~Stack() {}

    void push(const T& n);
    T top();
    void pop(); // {
    //     if (current == 0)
    //         throw StackException("Empty stack");

    //     current--;
    // }
};

template<typename T, int SIZE>
inline T Stack<T, SIZE>::top() {
    if (current == 0)
        throw StackException("Empty stack");

    return data[current-1];
}

// Se poate sa o implementezi in clasa si scapi de...
template<typename T, int SIZE>
inline void Stack<T, SIZE>::pop() {
    if (current == 0)
        throw StackException("Empty stack");

    current--;
}

template<typename T, int SIZE>
inline void Stack<T, SIZE>::push(const T& n) {
    if (current == SIZE)
        throw StackException("Full stack");

    data[current] = n;
    ++current;
}

#endif // STACK_H