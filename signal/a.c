#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

volatile sig_atomic_t g = 0;

static void hoge(int signum)  // (l .text)
{
    g = signum;




}

int main()  // (g .text)
{
    struct sigaction act;

    act.sa_handler = hoge;
    sigaction(SIGINT, &act, NULL);  // 2: Ctrl + C
    // sigaction(SIGKILL, &act, NULL);  // 9
    sigaction(SIGTERM, &act, NULL);  // 15: kill pid

    while(!g)
    {
        sleep(1);
    }

    printf("%c\n", g + '0');

    return 0;
}
