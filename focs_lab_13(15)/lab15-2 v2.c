#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N (100000)

typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned long long ullint;

typedef struct{
    uint m, n;
} color_index;


int MAX(int a, int b){
    if (a > b){
        return a;
    }else{
        return b;
    }
}

int manheten(ushort m1, ushort n1,ushort m2, ushort n2)
{
    return abs(m1-m2) + abs(n1-n2);
}

int main()
{
    ushort i, j;
    bool colors[N] = {false}; 
    scanf("%hu %hu", &i, &j);
    ullint full_counter = 0;
    uint mas[i][j];
    uint max_color = 0;
    for (ushort m = 0; m != i; m++)
    {
        for (ushort n = 0; n != j; n++)
        {
            scanf("%u", &mas[m][n]);
            if (colors[mas[m][n]] == 0){
                colors[mas[m][n]] = 1;
                max_color = MAX(mas[m][n], max_color);
            }
        }
    }
    for (uint col = 1; col <= max_color; col++)
    {
        if (colors[col])
        {
            for (ushort m1 = 0; m1 < i; m1++)
            {
                for (ushort n1 = 0; n1 < j; n1++)
                {
                    if (m1 == i - 1 && n1 == j - 1){
                        break;
                    }
                    if (mas[m1][n1] == col){
                        for (ushort m2 = m1; m2 < i; m2++)
                        {
                            if (m2 == m1){
                                for (ushort n2 = n1 + 1; n2 < j; n2++)
                                {
                                    if (mas[m2][n2] == col){
                                        full_counter += manheten(m1, n1, m2, n2);
                                    }
                                }
                            }else{
                                for (uint n2 = 0; n2 < j; n2++)
                                {
                                    if (mas[m2][n2] == col){
                                        full_counter += manheten(m1, n1, m2, n2);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%llu", full_counter);
}