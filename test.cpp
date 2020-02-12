#include <iostream>
#include <string>

class Foo {
public:
    operator std::string() const { return "I am a foo!"; }
};
