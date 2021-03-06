## If you can read this list before the C++ interview, I think you can overcome it!


**1. Class can be divided into two categories:**

    1.1 Class Without Pointers --- Complex
    1.2 Class With Pointers ---- String


**2. inline function:**

    a) Functions expanded in line when it is called inline function. 

    b) When the inline function is called, whole code of the inline function
        gets inserted or substituted at the point of inline function call.

    c) It helps avoid the overhead of calling a function

    d) inline is just a recommandation but not a command

    e) following functions cannot be regarded as inline functions:

        e.1) with loop

        e.2) with static variables

        e.3) with recursive

        e.4) return type != void and return statement does not exist in the body

        e.5) with switch or goto
    
    *f) When a function is defined in the class body, it becomes the candidate of 
    an inline function automatically


**3. constructor basics**

    Complex(double r = 0, double i = 0 ):   

        re(r), im(r)                    //initialization list      

        {   }                           //function body

    3.1) construct an object using <default argument>: 

         Complex c1; 

    3.2) contruct an  object using all arguments

        Complex c2(1,2);
    
    3.3) construct an object dynamically in the heap
        Complex *pc = new Complex(4);

    3.4) Rules I : when specify the default argument, the right side argument must be specified
    before you try to specify the left argument's default argument

    3.5) Rule II:  when construct a class, the left side argument must be given before the value
    given to the right side argument 
    
    3.6) Rule III: when construction, use the initialization list to improve the efficiency

    3.7) Rule IV: for the class without pointer member, we usually do not need to write destructor


**4. constructor overloading**

    4.1) Error : overloading Complex(int i = 0, int r = 0) by Complex() --- Compiler will report an error of ambiguity

    4.2) Private Constructor: it will be used in the design pattern of Singleton

    4.3) const keyword after function argument list: we MUST remember to add keyword *const* after the function argument list if the 
        function is read only! It is very very very important. For example:

        const Complex c(1,2);

        c.print();  //compiler will report an error if the print is now a const function, because const object cannot call a member function without const as the keyword
    
    4.4) it will be disccussed more in the later part


**5. Pass by value VS pass by reference**

    5.1) Pass by Value: pushing into the stack occur, low efficiency

    5.2) Pass by reference

    5.3) Pass by reference to const :

        Complex& operator+= (const Complex& c){...} //then the passed value cannot be modified in the function body

    5.4) We need to remember we MUST use *const* keyword if we should use in case of some unexpected situations

**6. Return by reference VS Return by Value** 

    6.1) Return by Reference example

    inline Complex& _doapl(Complex *ths, const Complex &x)
    {
        ...
        return *ths;    //*ths as the returner, it does not need to know the type of the acceptor (value or reference)
    }

    If allowed, we much prefer using return by reference rather than return by value.


**7. friend**
    
    7.1) A friend of a class can access all the private and protected members of the class

    7.2) Example of a friend function:

    friend complex& _doapl( Complex*, const Complex &);

    7.3) If multiple objects are from the same class, then they are friends to each other

        Example:

            class A 
            {

                public:

                    int func const( const A& a )
                    {

                        return a.val;

                    }

            };

            int main()

            {

                A a1;

                A a2;

                a1.func(a2); //successful.

            }


**8. Basic Principal for Designing a Class**

8.1) Store the data in the private

8.2) Pass by reference as primary selection

8.3) Return by reference as primary selection

8.4) Add const keyword when properly

8.5) use initialization in constructor


**9. Basic Operator Overloading**

9.1) Example 1: member function

    inline Complex& operator+=( const Complex & ) //overload the operator +=
    {
       
        return _doapl(this, r);

    }


    here we return Complex& (reference) is for chaining calling:

    Complex c1, c2, c3;

    c1 += c2 += c1;

9.2) Example 2: non-member function

    inline Complex operator+ (const Complex &x, const Complex &y) //overload the operator +=
    {

        return Complex( x.real() + y.real() );

    }

9.3) Important Difference between 2 constructors: 
    
    In the Example 1, we use return by reference for 2 reason: efficiency and this pointer. The this pointer means that we return the object itself which will not 
    end its lifecycle after this function calling, so we can do it.

    In the Example 2, we must return by value for only 1 reason: the lifecycle of a temporary object in the function will end after returned from function.


9.4) An important function must be declared as global function (non-member)

    ostream& operator<< (ostream &os, const Complex& ) //os cannot be const, because we modify os when call os<<
    {

        ...;

        return os;

    }

9.5) Other examples:

    inline Complex operator+ (const Complex& x, const Complex& y ){};

    inline Complex operator+ (const Complex& x, const double& y ){};

    inline Complex operator+ (double &x, const Complex& y){};

    inline  bool operator== (const Complex& x, const Complex& y){};

    inline bool operator== (const Complex &x, const double &y ){};

    inline bool operator== (const double& x, const Complex& y){};


**10. Class with Pointers**

    ***Big threes in the Class with pointer : (1)Copy Constructor, (2)Copy Assignment (operator= overwrite) (3)Destructor***

    10.1 For class without pointers like Complex, if we do not decalre a copy constructor, the compiler will automatically define a deep copy constructor for us.

    10.2 For class with pointers like String, we must declare and define a copy constructor

    10.3 delete vs delete[]

        (1) For an array of objects from a class without pointers (eg. new Complex c[128]), delete and delete[] have the same effect to the array of objects from the class. 

        (2) For an array of objects from a class with pointers (eg. new String c[128]), we have to use delete[] to destruct the array of objects

        (3) Reason:

            Eg.1.

            String* p = new String[3];
            
            ......

            delete[] p; //calls 3 times destructors, which makes sure the all the dynamically allocated memory will be cleared


            Eg.2.

            String* p = new String[3]

            ....

            delete p; //only call once destructor, which cannot clear all the dynamically allocated memory for the array of String objects, and memory leak happens.


            Actually both delete and deletep[] free the pointer(s), the difference is the times of destructor called. 


    10.4 Why copy assignment needed?

            Avoid the memory leak. If we have 2 String objects S1 and S2, and the String class does not have copy assignment, what happened when S1 = S2 is that the data pointer in the S1 changes 
            
            to point to the data block pointed byt he S2, and the memory block of S1 is not correctly freed, which causes the the memory leak. 

            
            ---------------------------------------------------------------------------------------------------------------
            !!!Self Assignment in Copy Assignment Operator!!!

            String& String::operator=(const String& str)
            
            {
            
                if( this == & str)      //WE MUST CHECK SELF-ASSIGNMENT CASE HERE!!! VERY IMPORTANT
            
                {
            
                    return *this;
            
                }

                delete [] m_data;
                
                m_data = new char[strlen(str.m_data)+1];
                
                strcpy(m_data, str.m_data);
                
                return *this;
            
            }

            Self-Assignment Check is very important in Copy Assignment for 2 reason (1) efficiency: we can return *this in self-assignment case to improve efficiency

            (2)!Safety: If we do not have self-assignment check, we will delete the object itself when calling delete[] m_data, which will free the memory block pointed by the m_data, resulting the memory leak when calling the strcpy();


            -------------------------------------------------------------------------------------------------------------

    
    10.5 Why copy constructor needed?

            For example, when we create a String object using String str2(str1), where str1 is an object from the String class, we hope that our String str2 possesses its data pointer points to an 
            
            isolated memory block but not shares the same data block of str1, so we need to implement copy constructor for deep-copy construction. Otherwise, the compiler just adapts shallow copy 
            
            by default.


**11. Stack vs Heap**

    Stack : (1) a memory space in a scope. When we call a function, the function itself will create a stack to accept its arguments and return address.
            
            (2) Any varibale declared in the function body will be stored in the stack

            Eg. 

            Complex c(1,2);

            (3) Life Cycle: stack object, ended when the scope ended automatically. Also called auto object

    Heap:   (1) the global memory space allocated by the OS dynamically.  

            Eg.

            Complex *p = new Complex(3);

            (2) Life Cycle: heap object, ended when the delete is explicitly called.

            Eg.

            int main()
            
            {
                {

                    Complex *p = new Complex;   //memory leak happened, life cycle pointer p ended when the scope is over, and we miss the opportunity of delete the dynamic object after the scope

                }

            }

    static local objects:

            static Complex c(1,2); 

            (1) life cycle: the whole life cycle of the program.

    global objects:

            Complex c(1,2);

            ...

            int main(){} 

            (1) life cycle: the whole life cycle of the program. We can regard it as the global objects

     

**12. new vs delete**

    new:

        Complex *pc = new Complex(1,2); <=========================> void *mem = operator new(sizeof(Complex));
                                                                    
                                                                    Complex* pc = static_cast< Complex* > (mem)
                                                                    
                                                                    pc->Complex::Complex(1,2);  //Complex::Complex(pc,1 ,2 );  
                                                                
        So the new() operation can be separated into 3 steps:   (1) allocate a void* type memory

                                                                (2) Cast the void* type memory into the specific memory type

                                                                (3) call the constructor using the pointer, and the pointer points to the start point of the allocate memory


    delete:

        delete <=================================================>  Complex::~Complex(pc);  //call the destructor first
 
                                                                    operator delete(pc);    //internally calls the free(pc) to free the memory

        So the delete() operation can be separated into 2 steps:   (1) call the destructor first    

                                                                   (2) then free the memory pointed by the pointer


**13. static members**

    (1) Only one copy will be retained in the memory for each static members or static functions.

    (2) there is no implicit this pointer as an argument in the static member function

    (3) the static member must be defined outside the class declaration

    (4) static function can only process static data member

    (5) We have 2 ways to call static member functions: 
                                                        Complex::static_func(); //call by class name and scope solution
                                                        c.static_func()         //call by the object of the class

    (6) How static is used in the real application design?  Singleton. E.g.

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
               
                };
    

**14. basic template function vs template class**

    (1) template class

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

    (2) template function
    
    template <typename T>
    
    inline const T& _min(const T &a, const T &b)
    
    {
        
        return a < b ? a : b;
    
    }

    int main()
    
    {
        
    int a = _min<int>(2,3);

    double b = _min<int>(4,3);

    double c = _min(5,5);   //different from template class, compiler is able to deduce the argument type, and we sometimes do
                            //not need to explicitly declare the type like _min<int>

    std::cout<<a<<std::endl;
    
    std::cout<<b<<std::endl;
    
    std::cout<<c<<std::endl;

    }

    more about template function: 1. in STL <algorithm>, there are many function template
                                  
                                  2. For using <algorithm>, we are usually required to complete the operator overloading


**14. basic OOP**

    Big three in OOP : Inheritance, Composition, Delegation. These three class relationship are combined to be the foundation of the oop.

    (1) Composition: queue has a deuque, or queue is composed by the deque. More specifically, queue adpats deque's APIs to implement its APIs.

        ===> Design Pattern : Adapator: Created a new class by wrapping an existing class. Wrapping means open or close an API, modify an API, modify API's name and encapsulate a class

        Construction and Destruction of a Composition

            Construction : from internal to external

                            The conatiner calls the componet's default constructor =====> The container calls its constructor

            Destruction:   from external to internal

                            The container calls its destructor =====> The container calls its component destructor

                            --------------------------------------
                            |                Queue               | 
                            |              Container             |
                            |           ---------------          |
                            |           |             |          |
                            |           |             |          |
                            |           |    Deque    |          | 
                            |           | Components  |          |
                            |           ---------------          |
                            |                                    |
                            --------------------------------------   

    (2) Delegation: Also called composition by reference 
    
    class StringRep;

    class String
    
    {
    
    public:
    
        String();
    
        String(const char *s);
    
        String(const String &s);
    
        String operator=(const String &s);
    
        ~String();

    private:
    
        StringRep *rep; //pointer to implementation
    
    };

    class StringRep
    
    {
        
        StringRep(const char *cstr);
        
        ~StringRep();

        int count;
        
        char *rep;

        friend class String;
    
    };

    Different from Composition, (1)the delegating object create the delegated object as need.

                                (2)the delegating object and delegated object has the different life cycle

    
    Application in Real World: Copy On Write

        Reader1 ======> |                       |
        Reader2 ======> | Shared Resource       |
        Reader3 ======> |  (reference counting) |
            |
            |  Writer1     
            ---------> | New Resource |  
    
    (3) Inheritance
    
        1. is-a relationship.

        2. Construction vs Destruction

        Construction: Derived class calls based class default constructor ===> Derived class calls its own constructor

        Destruction : Derived class calls its own destructor ===> Derived class calls base class destructor 

    
        3.For base class, its destructor must be decalred as virtual!!! Otherwise undefined action will happened. So we should keep a good habit of
        
        declaring destructors to be virtual any class may be base sometimes.


        class Shape

        {
            
        public:

                virtual void draw() const = 0; //for different shape class, they must redefine the draw() 

                virtual void error(const string &msg);  //print the error message, and allow child class to redefine it    

                int objectID() const; //unified ID API for every objects whose base class is Shape

        }


        In short words, memeber functions when inheritance can be categorized to 3 types : 

          I.  non-virtual function: does want derived class to redefine it

          II. virtual function: allow derived class to redefine it and has a default definition

          III.pure virtual function: derived class has to redefine it 

    
    (4) Template Method --- An important OOP Design Pattern, where derived class is reponsible to implement detailed service code (overwrite virtual functions), based class is reponsible to 

        define a framework.

        Eg. MFC

    (5) More about inheritance and composition          Derived
                                                  _____________________
             [Base]                              |                     |
               /|\                               |     [ Base ]        |
                |                                |                     |
                |                                |     [Component]     |           
            [Derived]-------->[ Component ]      |_____________________|                     
            

            I. When construction: Derived::Derived() : Base(), Component() { ... };

            Calls Component and Base default constructors first and then calls its own constructor

            II. When Destruction: ~Derived(...) : { ... ; ~Component(); ~Base() }

            Calls its own destructor first and then calls Component and Base Default Constructors

                                                        Derived           
                                                  _____________________
             [Base]------>[Component]            |    Base             |   
               /|\                               |   ----------------- |
                |                                |   |  [Component]  | |     
                |                                |   |_______________| |              
            [Derived]                            |_____________________|   

            I. When constructor, Derived::Derived: Component(), Base() {....}; 

            Calls first the Component and then the base, at last the Derived's constructor

            II. When destrucyor, ~Derived::{....; ~Base(); ~Component();}

            Calls first the Derived's destructor, and then the Base destructor, then the Component Destructor

    (6) Observer Design Pattern : An important design pattern using delegation + inheritance


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

**15. conversion function VS non-explicit-one-argument constructor VS operator Overloading**

    Very ambiguous part, we need to clearly understand it.






**16. Pointer like classes**

Type I : smart pointer 

template <class T>
class shared_ptr
{
public:
    //2 special operator overloadings
    
    T &operator*() const //dereference
    {
        return *px;
    }

    T &operator->() const
    {
        return px;
    }

    shared_ptr(T& p) : px(p) {}

private:
    T *px;
    long *pn;
};


(1) almost all the smart pointer have to implement operator*(), operator->() and shared_ptr(T& p);

(2) We need to be careful about -> operator's continuous chaining property. E.g.

shared_ptr<Foo> sp(new Foo);

Foo f(*sp); //derefence

sp->memthod;   // sp->method() <==> px->method() !!! becasue the continuous chaining property of -> operator

Type II : Iterator

reference operator*() const
{
    return (*node).data;
}

pointer operator->() const
{
    return &(operator*());
}


**17. function-like classes**

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


**18. advanced template**

argument deduction: compiler will deduce the argument to compile function template.


class template:

function template:

member template:

Full specialization

partial specialization : standard specilization VS pointer specilization

variadic templates:


**19. auto**



**20. range-based for**

for( int i : {1, 2, 3, 4, 5})
{
    //statement
    std::cout<<i<<std::endl
}

for( auto elem : vec)
{
    std::cout<< cout
}

for( auto& elem : vec)
{
    ele *= 3
}

!!!one invalid operation

auto a;

a = find(c.begin(), c.end(), target);


**21. reference**

(1) A reference will give us a illusion that its size and address are as same as the referenced object.

(2) In the address space, a reference is internally an address (pointer)

(3) In the user space, a reference is an object

(4) a case where ambiguity happened:

    double imag(const double& im) {...}

    double imag(const double im) {...}

(5) const is also a part of the function signature


**22. vtbl vs vptr**



**23. const**

When 
    void func() const;
    void func();

    both exist in a class declaration, the const object can only call the void func() const,
                                       the non-const object can only call the void func();

**24. new vs delete**

1. overloading the new, delete, new[], delete[] for global environment

inline void* operator new(size_t size)
{
    return malloc(size);
}

inline void* operator new[](size_t size)
{
    return malloc(size);
}


inline void operator delete(void* ptr)
{
    free(ptr);
}

inline void operator delete[](void* ptr)
{
    free(ptr);
}

2. overloading new/delete for members

class Foo
{
    public:

        void* operator new(size_t);
        void operator delete(void*, size_t);
        void* operator new[](size_t)
        {};
        void* operator delete[](void*, size_t);
}

I. Foo *p = new Foo;

===>

try
{
        void* mem = operator new(sizeof(Foo));
        p = static_cast<Foo*>(mem);
        p->Foo::foo();
}


II. delete p;

p->~Foo();
operator delete(p);




III. Foo *p = new Foo[N];

===>

try
{
        void* mem = operator new(sizeof(Foo) *N + 4);
        p = static_cast<Foo*>(mem);
        p->Foo::foo();//N times
}


IV. delete[] p;

===>

p->~Foo();  //N times
operator delete(p);






    
