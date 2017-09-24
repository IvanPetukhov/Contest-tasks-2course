#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <sys/types.h>

enum
{
SIZE_INT = 4,
SIZE_STRUCT = 12
};
struct node
{
int key;
int left_idx;
int right_idx;
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
print_tree(int fd, int pos)
{
int key, right, left;
lseek(fd, pos, SEEK_SET);
my_read(fd, &key, SIZE_INT);
lseek(fd, pos + SIZE_INT, SEEK_SET);
my_read(fd, &left, SIZE_INT);
lseek(fd, pos + 2 * SIZE_INT, SEEK_SET);
my_read(fd, &right, SIZE_INT);
if (right){
print_tree(fd, right * SIZE_STRUCT);
}
printf("%d\n", key);
if (left){
print_tree(fd, SIZE_STRUCT * left);
}
return;
}
int
main(int argc, char **argv)
{
int fd;
fd = open(argv[1], O_RDONLY);
print_tree(fd, 0);
close(fd);
return 0;
}
