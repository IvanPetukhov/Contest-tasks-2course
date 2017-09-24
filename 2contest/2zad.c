#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<fcntl.h>
#include<unistd.h>
enum{ SIZEOFBUF = 16};

int
main(void)
{
    char buf[SIZEOFBUF];
    int nread = 0, sign = 1, i, ft = 1;
    long long a = 0, sum = 0;
    while((nread = read (0, buf, sizeof(buf))) > 0){
        for (i = 0; i < nread; i++){
            if (isspace(buf[i])){
                a *= sign;
                sum += a;
                a = 0;
                sign = 1;
            }
            if (buf[i] == '+'){
                a *= sign;
                sum += a;
                sign = 1;
                a = 0;
            }
            if (buf[i] == '-'){
                a *= sign;
                sum += a;
                sign = -1;
                a = 0;
            }
            if (isdigit(buf[i])){
                a = a * ft + (buf[i] - '0');
                ft = 10;
            }
        }
    }
    a *= sign;
    sum += a;
    printf("%lld\n", sum);
    return 0;
}
