#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main() {
        printf("%d %d\n", getpid(), getppid());
        int e = execlp("ls", "ls", NULL);
        printf("%d\n", e);
        return 0;
}
