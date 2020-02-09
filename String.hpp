#ifndef _STRING_HPP_
#define _STRING_HPP_

#include <cstring>
#include <cstdlib>
#include <iostream>

class String
{
private:
    char* m_data;
    int length;

public:

    inline String(const char* p = 0)
    {
        if(!p)
        {
            length = 0;
            m_data = new char[1];
            *m_data = '\0';
        }
        else
        {
            m_data = new char[strlen(p)+1];
            strcpy(m_data, p);
        } 

    }

    inline String(const String &str)
    {
        m_data = new char[strlen(str.m_data)+1];
        strcpy(m_data, str.m_data);
    }

    inline ~String()
    {
        delete[] m_data;
    }

    inline String& operator=(const String &str)
    {
        if( &str == this)
        {
            //.do nothing..//
        }
        else
        {
            delete[] m_data;
            m_data = new char[strlen(str.m_data)+1];
            strcpy(m_data, str.m_data);
        }
        return *this;
    }

    inline char* get_c_str() const
    {
        return m_data; 
    }

    friend std::ostream& operator<<(std::ostream &os, const String &str);
};

std::ostream& operator<<(std::ostream &os, const String &str)
{
    os<<str.get_c_str();
    return os;
}

#endif