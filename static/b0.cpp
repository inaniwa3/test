#include <cstdio>

class Hoge
{
private:
    int val_0_;


};



       Hoge hoge_a; // g .bss
static Hoge hoge_b; // l .bss

int main()
{
    printf("%d\n", sizeof(Hoge));  // 4

           Hoge hoge_c; //
    static Hoge hoge_d; // l .bss

    return 0;
}
