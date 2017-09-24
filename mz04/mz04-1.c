#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <sys/types.h>

enum
{
    SIZE_NUM = 9,
    SIZE_INT = 32
};
int
main(int argc, char **argv)
{
    int x, a;
    int i, j;
    for(i = 1; i <= argc - 1; i++){
        sscanf(argv[i], "%o", &x);
        for (j = 0; j < 9; j++){
            a = x >> (SIZE_NUM - j - 1);
            a <<= SIZE_INT - 1;
            a >>= SIZE_INT - 1;
            if(a){
                switch(j){
                case 0:
                    printf("r");
                    break;
                case 1:
                    printf("w");
                    break;
                case 2:
                    printf("x");
                    break;
                case 3:
                    printf("r");
                    break;
                case 4:
                    printf("w");
                    break;
                case 5:
                    printf("x");
                    break;
                case 6:
                    printf("r");
                    break;
                case 7:
                    printf("w");
                    break;
                case 8:
                    printf("x");
                default:
                    break;
                }
            }
            if(!a){
                switch(j){
                case 0:
                    printf("-");
                    break;
                case 1:
                    printf("-");
                    break;
                case 2:
                    printf("-");
                    break;
                case 3:
                    printf("-");
                    break;
                case 4:
                    printf("-");
                    break;
                case 5:
                    printf("-");
                    break;
                case 6:
                    printf("-");
                    break;
                case 7:
                    printf("-");
                    break;
                case 8:
                    printf("-");
                default:
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}

