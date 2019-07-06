// https://cpplover.blogspot.com/2010/08/overloadoverridehiding.html

#include <cstdio>

class Hoge
{
public:
    void f()
    {
        puts("a");
    }
};

class Hoge2 : public Hoge
{
public:
};

class Hoge3 : public Hoge
{
public:
    void f()       // hiding (not override)
    {
        printf("c");
        Hoge::f();
    }
};

class Hoge4 : public Hoge
{
public:
    void f(int n)  // hiding (not override)
    {
        printf("d");
//      f();  // error: no matching function for call to 'Hoge4::f()'
        Hoge::f();
    }
};

int main()
{
    Hoge hoge;
    hoge.f();   // a

    Hoge2 hoge2;
    hoge2.f();  // a

    Hoge3 hoge3;
    hoge3.f();  // ca

    Hoge4 hoge4;
//  hoge4.f();  // error: no matching function for call to 'Hoge4::f()'
    hoge4.f(0); // da
}
