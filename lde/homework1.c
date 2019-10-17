#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct timeval tv;
    float before, after = 0;
    int fd = open("homework1.c", O_RDONLY);
    gettimeofday(&tv, NULL);
    before = tv.tv_sec + tv.tv_usec / 1e6;
    char buf[128];
    for(int i= 0; i < 100000000; i++) {
        read(fd, buf, 0);
    }
    gettimeofday(&tv, NULL);
    after = tv.tv_sec + tv.tv_usec / 1e6;
    printf("the syscall time: %f\n", (after - before) / 1000000);
}