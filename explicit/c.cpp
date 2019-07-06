#include <cstdio>

class Hoge
{
public:
             Hoge(int a) {}
};

class Fuga
{
public:
    explicit Fuga(int a) {}
};

void FuncHoge (Hoge hoge) {}
void FuncFuga (Fuga fuga) {}

int main()
{
    //// https://ja.cppreference.com/w/cpp/language/copy_initialization

    // T object = other; (1)
    Hoge hogeA = 1;
//  Fuga fugaA = 1;

    // f(other)          (3)
    FuncHoge(1);  // ? difficult to read
//  FuncFuga(1);

    //// https://ja.cppreference.com/w/cpp/language/direct_initialization

    // T object ( arg ); (1)
    Hoge hogeB(1);
    Fuga fugaB(1);
}
