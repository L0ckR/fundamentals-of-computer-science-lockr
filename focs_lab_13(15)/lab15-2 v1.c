#include <stdio.h>
#include <stdlib.h>
#define N (10000)

typedef unsigned int uint;
typedef unsigned short ushort;


typedef struct{
    uint color;
    ushort m, n;
} color_index;

ushort manheten(ushort m1, ushort n1,ushort m2, ushort n2)
{
    return abs(m1-m2) + abs(n1-n2);
}

int comp (const void *_a, const void *_b)
{
    color_index *a = (color_index *) _a;
    color_index *b = (color_index *) _b;
    return a->color - b->color;
}



int main()
{
    ushort i, j;
    scanf("%hu %hu", &i, &j);
    color_index color_mas[i*j];
    uint k = 0;
    for (ushort m = 0; m < i; m++)
    {
        for (ushort n = 0; n < j; n++)
        {
            uint col;
            scanf("%u", &col);
            color_mas[k].color = col;
            color_mas[k].m = m;
            color_mas[k].n = n;
            k++;
        }
    }
    qsort(color_mas, i*j, sizeof(color_index), comp);
    unsigned long long int full_counter = 0;
    for (ushort f = 0; f < i*j - 1; ++f)
    {
        for (ushort z = f + 1; z < i*j; ++z)
        {
            if (color_mas[f].color == color_mas[z].color){
                if (f + 1 == z && z != i*j - 1 && color_mas[z + 1].color != color_mas[z].color){
                    full_counter += manheten(color_mas[f].m, color_mas[f].n, color_mas[z].m, color_mas[z].n);
                    f = z;
                    break;
                }
                full_counter += manheten(color_mas[f].m, color_mas[f].n, color_mas[z].m, color_mas[z].n);
                continue;
            }
            break;
        }
    }
    printf("%llu", full_counter);
    return 0;
}