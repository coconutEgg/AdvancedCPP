#include <string>
#include <iostream>
template <typename T, typename Alloc>
class vector
{

};

//partial specialization: arg number 
//we specialized the template here
//When we specialized, we need to declare the whole arg types in <> after class name 
template<typename Alloc>
class vector<bool, Alloc>
{

};



//partial specialization: arg type
template <typename T>
class C
{
    public:
    void print() const
    {
        std::cout<<"This is the standard specialization"<<std::endl;
    }

};

template <typename T>
class C<T*>
{
public:
    T* str;
    void print() const
    {
        std::cout<<"This is the pointer specialization"<<std::endl;
    }

};

// template <typename U>
// class C<U*>
// {

// };

int main()
{
    C<std::string> obj1;

    C<std::string*> obj2;

    obj1.print();
    obj2.print();
}