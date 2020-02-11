#include <iostream>

class Singleton
{
public:
    static Singleton& getInstance()
    {   
        static int flag = 0;
        if(!flag)
        {
            std::cout<<"a singleton created\n"<<std::endl;
            flag = 1;
        }
        
        static Singleton s;
        return s;
    }

    void setup()
    {
        n++;
    };

    void print()
    {
        std::cout << n << std::endl;
    }

private:
    int n;
    Singleton( ){};
    Singleton(const Singleton &);
    void operator=(Singleton const&);

    // static Singleton singleton ;
};

// Singleton Singleton::singleton = 0;

int main()
{
    Singleton::getInstance().setup();
    Singleton::getInstance().setup();
    Singleton::getInstance().setup();
    Singleton::getInstance().print();
}