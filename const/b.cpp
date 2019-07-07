#include <cstdio>

class Hoge
{
public:
    Hoge(int m) : m_(m) {};
    int m_;
};

Hoge g(-11);

void f0(      Hoge*       h)
{
    h->m_ = 0;
    h = &g;
    (void)h->m_;
    h->m_ = 10;
}
void f1(const Hoge*       h)
{
//  h->m_ = 1;
    h = &g;
    (void)h->m_;
//  h->m_ = 11;
}
void f2(      Hoge* const h)
{
    h->m_ = 2;
//  h = &g;


}
void f3(const Hoge* const h)
{
//  h->m_ = 3;
//  h = &g;


}

int main()
{
    Hoge h(-1);
    f0(&h);
    printf("%d %d\n", h.m_, g.m_);  // 0 10
    f1(&h);
    printf("%d %d\n", h.m_, g.m_);  // 0 10
    f2(&h);
    printf("%d %d\n", h.m_, g.m_);  // 2 10
    f3(&h);
    printf("%d %d\n", h.m_, g.m_);  // 2 10
}
