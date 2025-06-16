#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
int main(int argc, char *argv[]) {
        if (argc != 2)
                return 1;
        int fd = open(argv[1], O_RDONLY);
        if (fd == -1)
                return 1;
        int l = 0, w = 0, c = 0, flag = 0;
        while (1) {
                char buf[1];
                int r = read(fd, buf, 1);
                if (!r || r == -1) {
                        w += flag;
                        break;
                }
                c += 1;
                char symbol = buf[0];
                l += (symbol == '\n');
                int delimeter = (symbol == ' ' || symbol == '\t' || symbol == '\n');
                if (!(flag || delimeter)) {
                        w += 1;
                        flag = 1;
                }
                else if (delimeter)
                        flag = 0;
        }
        printf("%d %d %d %s\n", l, w, c, argv[1]);
        close(fd);
        return 0;
}
