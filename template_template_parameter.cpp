#include <list>
#include <string>

template <typename T>
class SmartPointer
{

};

template<typename T>
using Lst = std::list<T, std::allocator<T>>;

template <typename T, 
        template <typename T> class SmartPointer
        >
class XCLs
{
    private:
        SmartPointer<T> sp;

    public:

};

int main()
{
    XCLs<std::string, SmartPointer> sp;
}