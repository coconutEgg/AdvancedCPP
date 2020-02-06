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




    
