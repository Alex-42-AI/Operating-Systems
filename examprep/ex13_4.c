#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main() {
        int f = fork();
        printf("%d %d %d\n", f, getpid(), getppid());
        if (f) {
                int status;
                int w = wait(&status);
                printf("%d %d\n", w, status);
        }
        else {
                int e = execlp("ls", "ls", "-l", NULL);
                return e ? e == -1 : 0;
        }
        return 0;
}
