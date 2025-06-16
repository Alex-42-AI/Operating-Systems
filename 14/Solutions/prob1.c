#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
int main(int argc, char* argv[]) {
        if (argc < 3)
                return 1;
        int f = fork();
        if (f == -1)
                exit(1);
        if (!f) {
                int i;
                for (i = 1; i < argc; i++)
                        argv[i - 1] = argv[i];
                argv[argc - 1] = NULL;
                int res = execvp(argv[0], argv);
        }
        else {
                int status;
                int w = wait(&status);
                printf("%d %d\n", w, status);
        }
        return 0;
}
