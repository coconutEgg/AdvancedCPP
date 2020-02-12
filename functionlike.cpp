#include <iostream>

class multiplier
{
    private:

    int num;

    public:
    multiplier(int _num) : num(_num)
    {}

    int operator()(int n)
    {
        return n*num;
    }
};

int main()
{
    multiplier mult(3);

    std::cout<<mult(3)<<std::endl;

    int a[] = {1, 2, 3, 4, 5};

    for(int i = 0 ; i < 5; i ++ )
    {
        std::cout<<mult(a[i])<<std::endl;

    }
}