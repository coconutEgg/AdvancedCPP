1. Class can be divided into two categories:
    1.1 Class Without Pointers --- Complex
    1.2 Class With Pointers ---- String

2. inline function: 
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
    