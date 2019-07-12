#include <cstdio>

class Hoge
{
public:
    Hoge(int* p) : p(p) {}
    void Test0a()       { this->p = nullptr; }
    void Test0b()       { int* r = this->p; *r = 0; printf("%d\n", *p); }
//  void Test1a() const { this->p = nullptr; }
    void Test1b() const { int* r = this->p; *r = 1; printf("%d\n", *p); }
private:
    int* p;
};

int main()
{
    int a = -1;
    Hoge h(&a);

    h.Test0b();  // 0
    h.Test1b();  // 1
}
