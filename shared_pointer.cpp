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

    shared_ptr (T *p) : px(p) {}

private:
    T *px;
    long *pn;
};