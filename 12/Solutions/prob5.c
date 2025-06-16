#include<stdio.h>
#include<fcntl.h>
#include<string.h>
int main(int argc, char *argv[]) {
    if (argc != 2)
        return 1;
    int m, n;
    scanf("%d %d", &m, &n);
    if (m > n)
        return 0;
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return 1;
    int c = 1;
    while (1) {
        char buf[1];
        int r = read(fd, buf, 1);
        if (!r || r == -1)
            break;
        char s = buf[0];
        if (m <= c && c <= n)
            write(1, buf, 1);
        if (s == '\n') {
            c = 0;
            printf("\n");
        }
        c++;
    }
    close(fd);
    return 0;
}