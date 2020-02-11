#ifndef _OBSERVER_
#define _OBSERVER_
#include <vector>
#include <iostream>

class Observer;
class Subject;
class SubObserver;


class Observer
{
    public:
    virtual void update(Subject *sub, int value) = 0;
};

class SubObserver : public Observer
{
    public:
    SubObserver(Subject *sub = nullptr)
    {
        if(sub != nullptr)
            sub->attach(this);
    }

    void update(Subject *sub, int value)
    {
        std::cout<<"value "<<value<<std::endl;
    }
};

class Subject
{
    private:
    int m_value;
    std::vector<Observer*> m_views;

    public:
    void attach(Observer* obs)
    {
        m_views.push_back(obs);
    }

    void set_val(int val)
    {
        m_value = val;
        notify();
    }

    void notify()
    {
        for(int i = 0 ; i < m_views.size() ; i ++ )
        {
            m_views[i]->update(this, m_value); 
        }
    }
};

#endif