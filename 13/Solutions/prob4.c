#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main() {
        int f = fork();
        if (f) {
                int status;
                int w = wait(&status);
                printf("%d %d\n", status, w);
        }
        else {
                int e = execl("cat", "cat", 0);
                printf("%s, %d\n", "child", e);
        }
        printf("%d %d %d\n", getpid(), getppid(), f);
        return 0;
}
