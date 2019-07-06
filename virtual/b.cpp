#include <cstdio>

class Hoge
{
public:
    void f()
    {
    }
};

class Fuga
{
public:
    virtual void f()
    {
    }
};

int main()
{
    printf("%lu\n", sizeof(Hoge));  // 1
    printf("%lu\n", sizeof(Fuga));  // 8
}
