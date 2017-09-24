/*�� ����������� ������ ����� �������� ������ ������, ���������� ������������ �����, ����������� ����������� ���������. ������������ ���������� ���������� �������� ����� �������������� � ������ � ����� ������. ��� ������ ��������� ������ �� ����������� ����� ������ �������� ����� ����� � ���� ������ ������. ���� ������ �������� ������ ���������� �������, �������� ����� nan. � ������ ������� ����� �� �������� ������.
��� ������ ������ ������ ����������� ������� getline2. �� ��������� ����������� ������. ��� ������ ������������ ����� ����������� ������ %.10g.
�� ��������� �������� \n � ����� ������ ������.
�� ������ ������������ ������� (�� ��������� ��� �����) ��������� 4 �����.
������ �������� �������� ����� � ������ (12-8-4).
����� ������ ���� ���� � ������� �������� �� ������������� ����� ����� ���������� 20 ������.
�������� �������: MAX(0;50+BONUS(12;8;4)-4*ATTEMPTS-20/7d).*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getline2(FILE *f)
{
    char *str = NULL;
    int c, i = 0;
    int mem_free = 4;
    c = fgetc(f);
    if (c == EOF)
        return str;
    str = malloc(mem_free);
    str[i] = c;
    if (c == '\n'){
        str[i + 1] = '\0';
        return str;
    }
    while ((c = fgetc(f)) != EOF){
        if((i + 1) == mem_free){
            mem_free *= 2;
            str = realloc(str, mem_free * sizeof(str[0]));
        }
        i++;
        str[i] = c;
        if (c == '\n'){
            break;
        }
    }
    if((i + 1) == mem_free){
        mem_free *= 2;
        str = realloc(str, mem_free * sizeof(str[0]));
    }
    str[i + 1] = '\0';
    return str;
}

int main(void)
{
    double x, sum;
    char *str;
    int k, flag = 0, nn;
    while((str = getline2(stdin)) != NULL){
        k = 0;
        sum = 0.0;
        flag = 0;
        while(sscanf(str + k, "%lf %n", &x, &nn) == 1){
            sum += x;
            k += nn;
            flag = 1;
        }
        if (flag == 0){
            printf("nan\n");
        } else {
            printf("%.10g\n", sum);
        }
        free(str);
    }
    return 0;
}
