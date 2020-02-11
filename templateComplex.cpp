#include <iostream>

template <typename T = double>
class Complex
{
public:
    Complex(T r = 0, T i = 0) : _real(r), _imag(i)
    {
    }

    Complex &operator+=(const Complex &r)
    {
        real += r.real;
        imag += r.imag;
        return *this;
    }

    T real() const { return _real; }

    T imag() const { return _imag; }


    //friend function is just declared here but not defined here, we need to
    //give it a template arg
    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const Complex<U> &c);

private:
    T _real;
    T _imag;
};

template <typename U>
std::ostream &operator<<(std::ostream &os, const Complex<U> &c)
{
    os << "[ " << c.real() << " , " << c.imag() <<"i"<< " ]";
    return os;
}

int main()
{
    Complex<double> c1(2,2);
    std::cout<<c1<<c1<<std::endl;
}