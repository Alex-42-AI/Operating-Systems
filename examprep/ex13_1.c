#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
int main() {
        printf("%d %d\n", getpid(), getppid());
        int res = execlp("ps", "ps", NULL);
        printf("%d\n", res);
        return 0;
}
