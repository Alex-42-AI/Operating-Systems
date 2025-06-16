#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(int argc, char *argv[]) {
        if (argc < 3)
                return 1;
        int f0 = fork();
        if (f0 == -1)
                return 1;
        if (f0) {
                int status0;
                wait(&status0);
                if (WIFEXITED(status0) && !WEXITSTATUS(status0)) {
                        int f1 = fork();
                        if (f1 == -1)
                                return 1;
                        if (f1) {
                                int status1;
                                wait(&status1);
                                if (WIFEXITED(status1))
                                        return WEXITSTATUS(status1);
                        }
                        else {
                                return execlp(argv[2], argv[2], NULL);
                        }
                }
                if (WIFEXITED(status0)) {
                        return WEXITSTATUS(status0);
                }
        }
        else {
                return execlp(argv[1], argv[1], NULL);
        }
        return 0;
}
