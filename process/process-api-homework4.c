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
        printf("I am child\n");
    } else {
        // parent process
        printf("I am parent\n");
    }
}