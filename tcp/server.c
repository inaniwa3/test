#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main()
{
    int fd_listen = socket(AF_INET, SOCK_STREAM, 0); // IPv4, TCP

    // skip bind

    listen(fd_listen, 5);

    struct sockaddr_in addr;
    socklen_t addrlen;
    int fd = accept(fd_listen, (struct sockaddr *)(&addr), &addrlen); // block

    const char* str = "hoge";
    write(fd, str, sizeof(str));
    printf("server: write [%s]\n", str);

    close(fd);

    close(fd_listen);

    return 0;
}
