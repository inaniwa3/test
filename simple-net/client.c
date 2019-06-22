#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    if (argc < 2) return 1;
    int port = atoi(argv[1]);

    int fd = socket(AF_INET, SOCK_STREAM, 0); // IPv4, TCP

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(port);

    connect(fd, (struct sockaddr *)(&addr), sizeof(addr));

    char buf[64];
    read(fd, buf, sizeof(buf));
    printf("client: read [%s]\n", buf);

    close(fd);

    return 0;
}
