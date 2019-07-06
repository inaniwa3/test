#include <cstdio>

class Hoge
{
public:
    ~Hoge()
    {
        puts("Destructor");
    }
};

void f()
{
    Hoge hoge;
}

int main()
{
    f();
    puts("end");

    return 0;
}

// $ ./a.out
// Destructor
// end
