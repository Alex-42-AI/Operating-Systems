#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdio.h>
int main(int argc, char *argv[]) {
        if (argc < 3)
                return 1;
        char *text = argv[1];
        int fd = open(argv[2], O_RDONLY);
        if (fd == -1)
                return 1;
        int i = 0;
        char line[81], c;
        while (read(fd, &c, 1) == 1) {
                if (c == '\n' || i > 79) {
                        line[i] = '\0';
                        if (strstr(line, text) != NULL) {
                                close(fd);
                                return 0;
                        }
                        i = 0;
                }
                else
                        line[i++] = c;
        }
        close(fd);
        return 1;
}
