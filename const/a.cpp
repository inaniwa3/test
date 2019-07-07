#include <cstdio>








char g[] = "def";

void f0(      char*       s)
{
    s[0] = '0';
    s = g;
    (void)s[1];
    s[1] = '0';
}
void f1(const char*       s)
{
//  s[0] = '1';
    s = g;
    (void)s[1];
//  s[1] = '1';
}
void f2(      char* const s)
{
    s[0] = '2';
//  s = g;


}
void f3(const char* const s)
{
//  s[0] = '3';
//  s = g;


}

int main()
{
    char s[] = "abc";
    f0(s);
    printf("%s %s\n", s, g);  // 0bc d0f
    f1(s);
    printf("%s %s\n", s, g);  // 0bc d0f
    f2(s);
    printf("%s %s\n", s, g);  // 2bc d0f
    f3(s);
    printf("%s %s\n", s, g);  // 2bc d0f
}
