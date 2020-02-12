#include <iostream>

template <class T>
const T& Min(const T &t1, const T &t2)
{
    return t1 < t2 ? t1 : t2;
}

class Stone
{
    public:

    Stone(int w, int h, int we) : _w(w), _h(h), _weight(we)
    {}

    bool operator< (const Stone &rhs) const
    {
        return this->_weight < rhs._weight;
    }
    int _w;
    int _h;
    int _weight;
};


int main()
{
    Stone st1(1,2,3);
    Stone st2(3,2,2);

    std::cout<< Min(st1, st2)._weight <<std::endl;

}