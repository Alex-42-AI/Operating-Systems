#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc, char *argv[]) {
        if (argc < 2)
                return 1;
        int n, m;
        scanf("%d %d", &m, &n);
        if (m > n)
                return 0;
        int fd = open(argv[1], O_RDONLY);
        if (fd == -1)
                return 1;
        int i = 1;
        while (1) {
                char buf[1];
                int r = read(fd, buf, 1);
                if (!r || r == -1)
                        break;
                char s = buf[0];
                if (m <= i && i <= n) {
                        write(1, buf, 1);
                }
                if (s == '\n') {
                        if (i > n)
                                printf("\n");
                        i = 0;
                }
                i++;
        }
        close(fd);
        return 0;
}
