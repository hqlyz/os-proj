#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int pipefd[2];
    int result = pipe(pipefd);
    if(result < 0) {
        printf("pipe failed\n");
        exit(1);
    }
    int rc1 = fork();
    if(rc1 < 0) {
        printf("fork failed\n");
        exit(1);
    } else if(rc1 == 0) {
        // child process 1
        close(pipefd[1]);
        char buf[256];
        read(pipefd[0], buf, sizeof(buf));
        printf(buf);
        printf("child process 1 exit\n");
    } else {
        // parent child 
        int rc2 = fork();
        if(rc2 < 0) {
            printf("fork failed\n");
            exit(1);
        } else if(rc2 == 0) {
            // child process 2
            close(pipefd[0]);
            char *buf = "good\n";
            write(pipefd[1], buf, strlen(buf));
            printf("child process 2 exit\n");
        } else {
            wait(NULL);
            close(pipefd[0]);
            close(pipefd[1]);
            printf("parent process exit\n");
        }
    }
}