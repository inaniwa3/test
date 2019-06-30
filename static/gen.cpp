#include <cstdio>

int main(int argc, char *argv[])
{
    for (int i = 0; i < 8; ++i) {
        printf("    %5s %6s int %s_%c%4s;  //\n",
            i & 4 ? "const" : "",
            i & 2 ? "static" : "",
            argv[1],
            'a' + i,
            i & 1 ? " = 1" : ""
        );
    }

    return 0;
}
