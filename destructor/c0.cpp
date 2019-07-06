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

int main()
{
    Hoge* pHoge = new Hoge2();
    delete pHoge;  //
                   // a

    return 0;
}
