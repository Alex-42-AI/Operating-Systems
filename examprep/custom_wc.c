#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int delimeter(char c) {
        return c == '\n' || c == '\t' || c == ' ';
}
int main(int argc, char *argv[]) {
        int i, total = 0, total_l = 0, total_w = 0, total_c = 0;
        for (i = 1; i < argc; i++) {
                int fd = open(argv[i], O_RDONLY);
                if (fd == -1) {
                        printf("wc: %s: No such file or directory\n", argv[i]);
                        continue;
                }
                int l = 0, w = 0, c = 0;
                while (1) {
                        char buf[1];
                        int r = read(fd, buf, 1);
                        if (!r || r == -1)
                                break;
                        c++;
                        char s = buf[0];
                        if (delimeter(s)) {
                                w++;
                                l += (s == '\n');
                        }
                }
                total_l += l; total_w += w; total_c += c;
                printf("%d %d %d %s\n", l, w, c, argv[i]);
                close(fd);
                total++;
        }
        if (total > 1)
                printf("%d %d %d total\n", total_l, total_w, total_c);
        return 0;
}
