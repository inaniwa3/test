#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>



static void hoge(int signum)  // (l .text)
{
    // https://linuxjm.osdn.jp/html/LDP_man-pages/man7/signal.7.html#lbAK
    char c = signum + '0';
    write(STDOUT_FILENO, &c, 1);  // '2' or '?'
    write(STDOUT_FILENO, "\n", 1);
    _exit(0);
}

int main()  // (g .text)
{
    struct sigaction act;

    act.sa_handler = hoge;
    sigaction(SIGINT, &act, NULL);  // 2: Ctrl + C
    // sigaction(SIGKILL, &act, NULL);  // 9
    sigaction(SIGTERM, &act, NULL);  // 15: kill pid

    while(1)
    {
        sleep(1);
    }



    return 0;
}
