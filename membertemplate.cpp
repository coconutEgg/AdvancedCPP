template <class T1, class T2>
struct  pair
{
    typedef T1 first_type;
    typedef T2 second_type;

    T1 first;
    T2 second;

    pair()
    :first(T1()), second(T2()) {}

    pair(const T1 &a, const T2 &b)
    :first(a), second(b){}

    template <class U1, class U2>
    pair(const pair<U1,U2>& p)
    :first(p.first), second(p.second){}

};

class __shared_ptr;

template<typename _Tp>
class shared_ptr : public __shared_ptr<_Tp>
{
    typename<typename _Tp1>
    explicit shared_ptr(_Tp1* __p)
    :shared_ptr<_Tp>(__p){}
};

//standard generic
template <class Key>
struct hash{    };

//if Key is char type
template<>
struct hash<char>
{

};

//if Key is int type
template<>
struct hash<int>
{

};

//if key is long type
template<>
struct hash<long>
{

};