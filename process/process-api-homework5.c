#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int rc = fork();
    if(rc < 0) {
        printf("fork failed\n");
        exit(1);
    } else if(rc == 0){
        // child process
        waitpid(rc, NULL, 0);
        printf("child process exit\n");
    } else {
        // parent process
        printf("parent process exit\n");
    }
    return 0;
}