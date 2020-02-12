#include <iostream>
#include <sstream>

class Male{};
class Female{};

template <typename Sex>
class People
{};

template <>
class People<Male>
{
    public:
    std::string operator()(int age)
    {
        std::stringstream ss;
        ss<<" I am a male, my age is "<< age<<std::endl;
        return ss.str();
    };
};

template <>
class People<Female>
{
    public:
    std::string operator()(int age)
    {
        std::stringstream ss;
        ss<<" I am a female, my age is "<< age<<std::endl;
        return ss.str();
    }
};

int main()
{
    std::cout<<People<Male>()(1000) ;
    std::cout<<People<Female>()(1200) ;
}