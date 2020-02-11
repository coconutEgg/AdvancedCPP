#include <iostream>

template <typename T>
inline const T& _min(const T &a, const T &b)
{
    return a < b ? a : b;
}

int main()
{
    int a = _min<int>(2,3);

    double b = _min<int>(4,3);

    double c = _min(5,5);

    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    std::cout<<c<<std::endl;
}