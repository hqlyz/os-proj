#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int rc = fork();
    if(rc < 0) {
        exit(1);
    } else if(rc == 0) {
        // child process
        printf("hello\n");
    } else {
        // parent process
        wait(NULL);
        printf("goodbye\n");
    }
    return 0;
}