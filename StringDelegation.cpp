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