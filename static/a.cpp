// symbol, section

// objdump -x a.out | grep hoge
                 int hoge_a    ;  // g .bss
                 int hoge_b = 1;  // g .data
          static int hoge_c    ;  // l .bss
          static int hoge_d = 1;  // l .data
//  const        int hoge_e    ;  //
    const        int hoge_f = 1;  // l .rodata
//  const static int hoge_g    ;  //
    const static int hoge_h = 1;  // l .rodata

namespace
{
                 int piyo_a    ;  // l .bss
                 int piyo_b = 1;  // l .data
          static int piyo_c    ;  // l .bss
          static int piyo_d = 1;  // l .data
//  const        int piyo_e    ;  //
    const        int piyo_f = 1;  // l .rodata
//  const static int piyo_g    ;  //
    const static int piyo_h = 1;  // l .rodata
}

namespace abcd
{
                 int efgh_a    ;  // g .bss
                 int efgh_b = 1;  // g .data
          static int efgh_c    ;  // l .bss
          static int efgh_d = 1;  // l .data
//  const        int efgh_e    ;  //
    const        int efgh_f = 1;  // l .rodata
//  const static int efgh_g    ;  //
    const static int efgh_h = 1;  // l .rodata
}

int main()
{
                 int fuga_a    ;  //
                 int fuga_b = 1;  //
          static int fuga_c    ;  // l .bss
          static int fuga_d = 1;  // l .data
//  const        int fuga_e    ;  //
    const        int fuga_f = 1;  //
//  const static int fuga_g    ;  //
    const static int fuga_h = 1;  // l .rodata

    return 0;
}
