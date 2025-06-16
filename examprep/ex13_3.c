#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main() {
        printf("%d %d\n", getpid(), getppid());
        int f = fork();
        printf("%d\n", f);
        if (f) {
                int status;
                int w = wait(&status);
                printf("%d %d\n", w, status);
        }
        return 0;
}
