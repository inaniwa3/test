#include <cstdio>

class Hoge
{
public:
    ~Hoge()
    {
        puts("a");
    }
};

class Hoge2 : public Hoge
{
public:
    ~Hoge2()
    {
        puts("b");
    }
};

void f0()
{
    Hoge hoge;
}
void f1()
{
    Hoge2 hoge2;
}
void f2()
{
    Hoge* pHoge = new Hoge();
    // leak
}
void f3()
{
    Hoge* pHoge = new Hoge();
    delete pHoge;
}
void f4()
{
    Hoge2* pHoge2 = new Hoge2();
    // leak
}
void f5()
{
    Hoge2* pHoge2 = new Hoge2();
    delete pHoge2;
}

int main()
{
    f0();  // a
    puts("----");
    f1();  // b
           // a
    puts("----");
    f2();  // 
    puts("----");
    f3();  // a
    puts("----");
    f4();  // 
    puts("----");
    f5();  // b
           // a
    puts("----");

    return 0;
}
