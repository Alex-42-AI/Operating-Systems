#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main() {
    int f = fork();
    if (f == -1)
        return 1;
    printf("%d %d %d\n", getpid(), getppid(), f);
    return 0;
}

