#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
int main(int argc, char *argv[]) {
        if (argc < 2)
                return 1;
        if (fork()) {
                int status;
                int w = wait(&status);
                printf("%d %d\n", w, status);
        }
        else {
                int i;
                for (i = 1; i < argc; i++)
                        argv[i - 1] = argv[i];
                execvp(argv[0], argv);
        }
        return 0;
}
