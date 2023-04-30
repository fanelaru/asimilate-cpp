#include <iostream>
#include <cstring>

constexpr char url_name[] = "prp-url://adresa";
constexpr char url_prefix[] = "prp-url://";

class MyClass {};

int main()
{
    const char* str = strstr(url_name, url_prefix);

    if (str == url_name) {
        str += strlen(url_prefix);
        std::cout << "String la fel" << std::endl;
    }
    else {
        std::cout << "String diferit" << std::endl;
    }

    const char arr[] = "giginel";

    for (const char& c : arr)
    {
        std::cout << c;
    }

    MyClass* obj = new MyClass();

    MyClass** objArray = new MyClass*[10]();

    *objArray = obj;
}