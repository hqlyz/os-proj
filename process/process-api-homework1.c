#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int x = 100;
    int rc = fork();
    if(rc < 0) {
        exit(1);
    } else if(rc == 0) {
        // child process
        printf("before: the x value of child is %d\n", x);
        x = 200;
        printf("after: the x value of child is %d\n", x);
    } else {
        // parent process
        printf("before: the x value of parent is %d\n", x);
        x = 300;
        printf("after: the x value of parent is %d\n", x);
    }
}