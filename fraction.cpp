#include <iostream>
#include <string>
#include <sstream>

class Fraction
{
public:
    Fraction(int num, int den = 1)
    : m_numerator(num), m_denominator(den) {}

    // operator double() const //no need to declare the return type
    // {
    //     return (double)(m_numerator / m_denominator);
    // }

    operator std::string() const
    {
        return "hello world";
    }

private:
    int m_numerator;
    int m_denominator;
};


int main()
{
    Fraction f(3,2);
    // double a = f + 2;   //operator double(){} will convert f automatically to a double value
    // double b = f + 15;
    // double c = 16 + f;

    

    std::cout<< f <<std::endl;

    // std::cout<<a<<std::endl;
    // std::cout<<b<<std::endl;
    // std::cout<<c<<std::endl;
}