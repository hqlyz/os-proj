#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int arc, char *argv[]) {
    int fd = open("test1", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    int rc = fork();
    if(rc < 0) {
        exit(1);
    } else if(rc == 0) {
        // child process
        char buf_child[100];
        sprintf(buf_child, "this is from child\n");
        write(fd, buf_child, strlen(buf_child));
        fsync(fd);
        close(fd);
        printf("%d closed by child\n", fd);
    } else {
        // parent process
        char buf_parent[100];
        sprintf(buf_parent, "this is from parent\n");
        write(fd, buf_parent, strlen(buf_parent));
        fsync(fd);
        close(fd);
        printf("%d closed by parent\n", fd);
    }
}