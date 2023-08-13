#include <iostream>

template<class T> 
// or template<typename T> class a fost inainte de typename
// aici au acelasi rol
const T& max(const T& a, const T& b) {
    return (a>b) ? a : b;
}

template<class T>
const T& min(const T& a, const T& b) {
    return (a<b) ? a : b;
}



int main() {

    int a=3, b=4;

    std::cout << "max(a,b) = " << max(a,b) << std::endl;
    std::cout << "max(a,b) = " << max<double>(4,5.5) << std::endl;
    return 0;
}