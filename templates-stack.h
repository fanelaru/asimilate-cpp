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

template<typename T>
class Stack {
    T *data;
    size_t size;
    size_t current;
public:
    Stack(size_t s) : size{s}, current{0}, data{new T[s]} {}
    ~Stack() {delete [] data;}

    void push(const T& n);
    T top();
    void pop() {
        if (current == 0)
            throw StackException("Empty stack");

        current--;
    }
};

template<typename T>
inline T Stack<T>::top() {
    if (current == 0)
        throw StackException("Empty stack");

    return data[current-1];
}

// Se poate sa o implementezi in clasa si scapi de...
// template<typename T>
// inline void Stack<T>::pop() {
//     if (current == 0)
//         throw StackException("Empty stack");

//     current--;
// }

template<typename T>
inline void Stack<T>::push(const T& n) {
    if (current == size)
        throw StackException("Full stack");

    data[current] = n;
    ++current;
}

#endif // STACK_H