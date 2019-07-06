#include <cstdio>

class Hoge
{
public:
    // https://ja.cppreference.com/w/cpp/language/default_constructor
    // https://ja.cppreference.com/w/cpp/language/converting_constructor
    Hoge()                // converting constructor (c++11 ~)
    {
        printf("z");
    }
};

class Fuga
{
public:
    // https://ja.cppreference.com/w/cpp/language/default_constructor
    // https://ja.cppreference.com/w/cpp/language/converting_constructor
    explicit Fuga()       //   explicit constructor
    {
        printf("z");
    }
};

int main()
{
    // https://ja.cppreference.com/w/cpp/language/default_initialization de
    // https://ja.cppreference.com/w/cpp/language/direct_initialization  di
    printf(  "hogeA "); Hoge hogeA;    // z (default init: T obj;       de-(1)          )
    printf("\nhogeB "); Hoge hogeB();  // - (a function declaration)
    printf("\nhogeC "); Hoge hogeC{};  // z ( direct init: T obj {arg}; di-(2) (c++11 ~))
    printf("\nfugaA "); Fuga fugaA;    // z (default init: T obj;       de-(1)          )
    printf("\nfugaB "); Fuga fugaB();  // - (a function declaration)
    printf("\nfugaC "); Fuga fugaC{};  // z ( direct init: T obj {arg}; di-(2) (c++11 ~))
    puts("");
}
