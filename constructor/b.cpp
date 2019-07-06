// http://www.cplusplus.com/doc/tutorial/classes2/

#include <cstdio>

class Hoge
{
public:
    Hoge()
    {
        puts("Default constructor");
    }

    Hoge(const Hoge& a)
    {
        puts("Copy constructor");
        m = a.m;
    }

    Hoge& operator= (const Hoge& a)
    {
        puts("Copy assignment");
        m = a.m;
        return *this;
    }

    int m;
};

int main()
{
    // printf("sizeof(Hoge): %lu\n", sizeof(Hoge));  // 4

    Hoge hogeA;         // Default constructor
    hogeA.m = 1;

    puts("----");

    Hoge hogeB(hogeA);  // Copy constructor (direct initialization)
    printf("hogeB.m: %d\n", hogeB.m);  // 1

    puts("----");

    Hoge hogeC = hogeB; // Copy constructor (copy initialization)
    printf("hogeC.m: %d\n", hogeC.m);  // 1

    puts("----");

    hogeB.m = 2;
    hogeC = hogeB;      // Copy assignment (hogeC.operator=(hogeB);)
    printf("hogeC.m: %d\n", hogeC.m);  // 2

    hogeB.m = 3;
    printf("hogeC.m: %d\n", hogeC.m);  // 2
}
