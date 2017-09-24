//This may be not correct
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <sys/types.h>

enum
{
    SIZE_INT = 4,
    SIZE_LONGLONG = 8,
    SIZE_STRUCT = 12
};

struct Data
{
    int x;
    long long y;
};

void
my_read(int fd, void *buf, long nbytes)
{
    char *p = buf;
    int nr;
    while(nbytes){
        nr = read(fd, p, nbytes);
        nbytes -= nr;
        p += nr;
    }
    return;
}
void
my_write(int fd, void *buf, long nbytes)
{
    char *p = buf;
    int nr;
    while(nbytes){
        nr = write(fd, p, nbytes);
        nbytes -= nr;
        p += nr;
    }
    return;
}

int
main(int argc, char **argv)
{
    int fd;
    int x1, x2;
    int A;
    int i;
    long long y1, y2;
    fd = open(argv[1], O_RDWR);
    sscanf(argv[2], "%d", &A);
    int n;
    int pos = 0;
    n = lseek(fd, 0, SEEK_END) / 12;
    for (i = 0; i < n/2; i++){
        lseek(fd, pos, SEEK_SET);
        my_read(fd, &x1, SIZE_INT);
        my_read(fd, &y1, SIZE_LONGLONG);
        y1 += A * x1;
        lseek(fd, - pos - SIZE_STRUCT, SEEK_END);
        my_read(fd, &x2, SIZE_INT);
        my_read(fd, &y2, SIZE_LONGLONG);
        y2 += A * x2;
        lseek(fd, pos, SEEK_SET);
        my_write(fd, &x2, SIZE_INT);
        my_write(fd, &y2, SIZE_LONGLONG);
        lseek(fd, - pos - SIZE_STRUCT, SEEK_END);
        my_write(fd, &x1, SIZE_INT);
        my_write(fd, &y1, SIZE_LONGLONG);
        pos += SIZE_STRUCT;
    }
    if (n % 2 != 0){
        lseek(fd, SIZE_STRUCT * (n/2 + 1), SEEK_SET);
        my_read(fd, &x1, SIZE_INT);
        my_read(fd, &y1, SIZE_LONGLONG);
        y1 += A * x1;
        lseek(fd, -SIZE_LONGLONG, SEEK_CUR);
        my_write(fd, &y1, SIZE_LONGLONG);
    }
    return 0;
}
