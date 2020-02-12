#include <iostream>

void print()
{

}

//where to put ... is just the question of grammer
template<typename T, typename ... Types> // frist place of ...
void print(const T& firstArg, const Types&... args) //second place of ...
{
    std::cout<<firstArg<<endl;
    print(args...); //recursive calls itself; third place of ...    
}