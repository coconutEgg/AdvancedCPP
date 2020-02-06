
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

**3. constructor**

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
    