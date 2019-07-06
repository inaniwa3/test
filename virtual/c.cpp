#include <cstdio>

class Hoge
{
public:
    virtual void f()
    {
        puts("a");
    }
    void ff()
    {
        puts("aa");
    }
};

class Hoge2 : public Hoge
{
public:
    void f() override
    {
        puts("b");
    }
    void ff()
    {
        puts("bb");
    }
};

class Hoge3 : public Hoge
{
public:
    void f() override
    {
        puts("c");
    }
    void ff()
    {
        puts("cc");
    }
};

int main()
{
    Hoge hoge;
    hoge.f();   // a

    Hoge2 hoge2;
    hoge2.f();  // b
    Hoge3 hoge3;
    hoge3.f();  // c

    ((Hoge*)(&hoge2))->f();  // b   // polymorphism
    ((Hoge*)(&hoge2))->ff(); // aa
    ((Hoge*)(&hoge3))->f();  // c   // polymorphism
    ((Hoge*)(&hoge3))->ff(); // aa
}
