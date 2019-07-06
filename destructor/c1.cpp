#include <cstdio>

class Hoge
{
public:
    virtual ~Hoge()
    {
        puts("a");
    }
};

class Hoge2 : public Hoge
{
public:
    ~Hoge2() override
    {
        puts("b");
    }
};

int main()
{
    Hoge* pHoge = new Hoge2();
    delete pHoge;  // b
                   // a

    return 0;
}
