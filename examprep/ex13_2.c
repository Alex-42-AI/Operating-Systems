#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
int main() {
        printf("%d %d %d\n", fork(), getpid(), getppid());
        return 0;
}
