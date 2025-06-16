#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(int argc, char *argv[]) {
        if (argc == 1) {
                char buf[1];
                while (1) {
                        int r = read(0, buf, 1);
                        if (!r || r == -1)
                                break;
                        write(1, buf, 1);
                }
        }
        else {
                int i;
                for (i = 1; i < argc; i++) {
                        int fd = open(argv[i], O_RDONLY);
                        if (fd == -1)
                                continue;
                        while (1) {
                                char buf[1];
                                int r = read(fd, buf, 1);
                                if (!r || r == -1)
                                        break;
                                write(1, buf, 1);
                        }
                        close(fd);
                }
        }
        return 0;
}
