// https://programming-place.net/ppp/contents/modern_cpp/language/015.html

#include <cstdio>

class Hoge
{
public:
    Hoge()
    {
        puts("a");
    }
    ~Hoge()
    {
        puts("b");
    }
};

class HogeWrapper
{
public:
    HogeWrapper()
        : m_hoge(new Hoge())
    {
    }
    ~HogeWrapper()
    {
        delete m_hoge;
    }
private:
    Hoge* const m_hoge;
};

void f()
{
    HogeWrapper hw;
}

int main()
{
    f();
    puts("end");
}
