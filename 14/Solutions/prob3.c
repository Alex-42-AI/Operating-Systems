#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char *argv[]) {
        if (argc != 3)
                return 1;
        int f = fork();
        if (f == -1)
                return 1;
        if (f) {
                int status0;
                wait(&status0);
                if (WIFEXITED(status0) && WEXITSTATUS(status0)) {
                        int f0 = fork();
                        if (f0 == -1)
                                return 1;
                        if (!f0) {
                                int e = execlp(argv[2], argv[2], NULL);
                                perror("execlp command2");
                                return e;
                        }
                        int status1;
                        wait(&status1);
                        if (WIFEXITED(status1))
                                return WEXITSTATUS(status1);
                        return 1;
                }
                if (WIFEXITED(status0))
                        return WEXITSTATUS(status0);
                return 1;
        }
        int e = execlp(argv[1], argv[1], NULL);
        perror("execlp command1");
        return e;
}
