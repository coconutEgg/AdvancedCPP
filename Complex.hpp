#ifndef __COMPLEX_HPP_
#define __COMPLEX_HPP_

#include <string>
#include <sstream>
#include <ostream>

class Complex
{
private:
    double real;
    double imag;

public:
    Complex(const double &_real = 0, const double &_imag = 0)
        : real(_real), imag(_imag)
    {}

    Complex(const Complex &c) : real(c.real), imag(c.imag)
    {}

    double _real() const
    {
        return this->real;
    }

    double _imag() const
    {
        return this->imag;
    }

    Complex &operator=(Complex &c)
    {
        this->real = c.real;
        this->imag = c.imag;
        return *this;
    }

    inline Complex &operator+(const Complex &c)
    {
        this->real += c.real;
        this->imag += c.imag;
        return *this;
    }

    inline Complex &operator-(const Complex &c)
    {
        this->real += c.real;
        this->imag += c.imag;
        return *this;
    }

    inline Complex &operator+=(const Complex &c)
    {
        this->real += c.real;
        this->imag += c.imag;
        return *this;
    }

    inline Complex &operator-=(const Complex &c)
    {
        this->real -= c.real;
        this->imag -= c.imag;
        return *this;
    }

    inline bool operator==(const double &n) const
    {
        return this->imag == 0 && this->real == n;
    }

    inline bool operator>(const double &n) const
    {
        return this->imag == 0 && this->real > n;
    }

    inline bool operator<(const double &n) const
    {
        return this->imag == 0 && n == this->real;
    }

    inline operator std::string() const
    {
        std::stringstream ss;
        ss << "[ " << real << " , " << imag << " ]";
        return ss.str();
    }

    friend inline double real(const Complex &c);

    friend inline double imag(const Complex &c);

    friend inline bool operator==(const double &n, const Complex &c);

    friend inline bool operator==(const Complex &c1, const Complex &c2);

    friend inline bool operator>(const double &n, const Complex &c);

    friend inline bool operator<(const double &n, const Complex &c);

    friend inline Complex& operator+=(const double &n, Complex &c);

    friend inline Complex& operator-=(const double &n, Complex &c);

    friend inline Complex operator+(const double &n, Complex &c);

    friend inline Complex operator-(const double &n, Complex &c);

    friend inline Complex operator+(Complex &c, const double &n);

    friend inline Complex operator-(Complex &c, const double &n);
    
    friend inline std::ostream& operator<<(std::ostream& os, Complex &c);
};

inline double real(const Complex &c)
{
    return c.real;
};

inline double imag(const Complex &c)
{
    return c.imag;
};

inline bool operator==(const Complex &c1, const Complex &c2)
{
    return c1.imag == c2.imag && c1.real == c2.real;
}

inline bool operator==(const double &n, const Complex &c)
{
    return !c.imag && n == c._real();
}

inline bool operator>(const double &n, const Complex &c)
{
    return n > c._real() && !c._imag();
}


inline bool operator<(const double &n,  Complex &c)
{
    return n > c._real() && !c._imag(); 
}

inline Complex& operator+=(const double &n,  Complex &c)
{
    c.real += n ;
    return c;
}

inline Complex& operator-=(const double &n, Complex &c)
{
    c.real -= n;
    return c;
}

inline Complex operator+(const double &n, Complex &c)
{
    Complex _c(c.real+n, c.imag);
    return _c;
}

inline Complex operator-(const double &n, Complex &c)
{
    Complex _c(c.real-n, c.imag);
    return _c;
}

inline Complex operator+(Complex &c, const double &n)
{
    Complex _c(c.real+n, c.imag);
    return _c;
}

inline Complex operator-(Complex &c, const double &n)
{
    Complex _c(c.real-n, c.imag);
    return _c;
}

inline std::ostream& operator<<(std::ostream& os, Complex &c)
{
    os<<"[ "<<c.real << " , "<< c.imag<<"i ]";
    return os;
}

#endif