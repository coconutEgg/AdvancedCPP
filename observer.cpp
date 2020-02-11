#include <vector>
#include <iostream>
#include "obs_observer.hpp"


int main()
{
    Subject sub;
    SubObserver obs1;
    SubObserver obs2;
    SubObserver obs3;

    sub.attach(&obs1);
    sub.attach(&obs2);
    sub.attach(&obs3);

    SubObserver obs4(&sub);

    sub.set_val(10);

    sub.notify();
}
