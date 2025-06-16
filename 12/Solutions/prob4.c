#include<stdio.h>
#include<fcntl.h>
int main(int argc, char *argv[]) {
        int i;
        for (i = 1; i < argc; i++) {
                int fd = open(argv[i], O_RDONLY);
                while (1) {
                        char buf[1];
                        int r = read(fd, buf, 1);
                        if (!r || r == -1)
                                break;
                        write(1, buf, 1);
                }
                close(fd);
        }
        return 0;
}
