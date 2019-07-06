#include <cstdio>

class Hoge
{
public:

    // https://ja.cppreference.com/w/cpp/language/converting_constructor
    Hoge(int a)           // converting constructor (copy init: o)
    {
        printf("z");
    }
};

class Fuga
{
public:

    // https://ja.cppreference.com/w/cpp/language/converting_constructor
    explicit Fuga(int a)  //   explicit constructor (copy init: x)
    {
        printf("z");
    }
};

int main()
{
    // https://ja.cppreference.com/w/cpp/language/copy_initialization   co
    // https://ja.cppreference.com/w/cpp/language/direct_initialization di
    printf(  "hogeA "); Hoge hogeA = 1; // z (  copy init: T obj = other; co-(1)          )
    printf("\nhogeB "); Hoge hogeB(1);  // z (direct init: T obj (arg);   di-(1)          )
    printf("\nhogeC "); Hoge hogeC{1};  // z (direct init: T obj {arg};   di-(2) (c++11 ~))
//  printf("\nfugaA "); Fuga fugaA = 1; //   (  copy init: T obj = other; co-(1)          )
    printf("\nfugaB "); Fuga fugaB(1);  // z (direct init: T obj (arg);   di-(1)          )
    printf("\nfugaC "); Fuga fugaC{1};  // z (direct init: T obj {arg};   di-(2) (c++11 ~))
    puts("");
}
