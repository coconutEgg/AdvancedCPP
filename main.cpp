#include "Complex.hpp"
#include "String.hpp"
#include <iostream>

int main()
{
    Complex c(1,2);
    std::cout<<c<<std::endl;

    Complex c2(2,3);
    std::cout<< ( c == c2 ?"true":"false")<<std::endl;

    Complex c3(1,2);
    std::cout<< ( c == c3 ?"true":"false")<<std::endl;

    std::cout<<c+c2<<std::endl;

    Complex c4 = c2 + 2;
    std::cout<<c4<<std::endl;

    Complex c5 = c4 +5;
    std::cout<<c5<<std::endl;

    c5 += c3;
    std::cout<<c5<<std::endl;

    c5 -= c;
    std::cout<<c5<<std::endl;

    Complex c6(c5);
    std::cout<<c6<<std::endl;

    c6 = c4;
    std::cout<<c6<<std::endl;

    std::cout<<c5<<c6<<std::endl;

    String str1("hello world");

    std::cout<<str1<<std::endl;

    String str2(str1);

    std::cout<<str2<<std::endl;

    String str3 = str1;

    std::cout<<str3<<std::endl;
    

}