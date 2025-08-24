#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main() {
    while (1) {
        char buf[1];
        int r = read(0, buf, 1);
        if (!r || r == -1)
            break;
        printf("%c", buf[0]);
    }
    return 0;
}
