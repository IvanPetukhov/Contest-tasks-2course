#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <limits.h>

int
main(int argc, char **argv)
{
    long long sum = 0;
    DIR *d;
    struct dirent *dd;
    d = opendir(argv[1]);
    while((dd = readdir(d))){
        if(!strcmp(dd->d_name, ".") || !strcmp(dd->d_name, "..")){
            continue;
        }
        struct stat buf;
        char str[PATH_MAX];
        snprintf(str, PATH_MAX, "%s/%s", argv[1], dd->d_name);
        if (lstat(str, &buf) < 0){
            continue;
        }
        if (S_ISREG(buf.st_mode)){
            sum += buf.st_size;
        }
    }
    printf("%lld", sum);
    return 0;
}
