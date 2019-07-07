#include <cstdio>

class Hoge
{
public:
    Hoge(int m) : m_(m) {};
    int m_;
};

Hoge g(-11);

void f0(      Hoge&       h)
{
    h.m_ = 0;
    h = g;
}
void f1(const Hoge&       h)
{
//  h.m_ = 1;
//  h = g;
}
// void f2(      Hoge& const h)
// {


// }
// void f3(const Hoge& const h)
// {


// }

int main()
{
    Hoge h(-1);
    f0(h);
    printf("%d\n", h.m_);  // -11
    f1(h);
    printf("%d\n", h.m_);  // -11
}
