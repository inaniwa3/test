#include <cstdio>

class Fuga
{
private:
    int val_0_;
    static int val_1_;
    static int val_2_;
};
int Fuga::val_1_;     // g .bss
int Fuga::val_2_ = 1; // g .data

       Fuga fuga_a; // g .bss
static Fuga fuga_b; // l .bss

int main()
{
    printf("%d\n", sizeof(Fuga));  // 4

           Fuga fuga_c; //
    static Fuga fuga_d; // l .bss

    return 0;
}
