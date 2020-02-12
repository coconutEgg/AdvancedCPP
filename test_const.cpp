#include<iostream>

class A
{
public:
    A(int _a = 0):a(_a){};

    void func()const 
    {
        std::cout<<"const function called\n";
    }

    void func()
    {
        std::cout<<"non const function called\n";
    }

    int a;
};

int main()
{
    const A a;
    A _a;

    a.func();
    _a.func();
}