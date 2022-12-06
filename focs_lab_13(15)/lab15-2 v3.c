#include <stdio.h>
#include <stdlib.h>
#define N (100000)

typedef long long ll;
 
 
typedef struct{
    ll color;
    ll m, n;
} color_index;
 
int comp_m (const void *_a, const void *_b)
{
    color_index *a = (color_index *) _a;
    color_index *b = (color_index *) _b;
    if (a->color == b->color){
        return a->m - b->m;
    }
    return a->color - b->color;
}
 
 
int comp_n (const void *_a, const void *_b)
{
    color_index *a = (color_index *) _a;
    color_index *b = (color_index *) _b;
    if (a->color == b->color){
        return a->n - b->n;
    }
    return a->color - b->color;
}
 
 
int main()
{
    ll i, j;
    scanf("%lld %lld", &i, &j);
    color_index color_mas[i*j];
    ll color_counter[N + 1] = {0};
    ll k = 0;
    for (ll m = 0; m < i; m++)
    {
        for (ll n = 0; n < j; n++)
        {
            ll col;
            scanf("%lld", &col);
            color_mas[k].color = col;
            color_mas[k].m = m;
            color_mas[k].n = n;
            color_counter[col] += 1;
            k++;
        }
    }
    ll full_counter = 0;
    ll f_color = color_mas[0].color;
    ll temp = 0;
    if (i > 1)
    {
        qsort(color_mas, i*j, sizeof(color_index), comp_m);
        for (ll f = 0; f < i*j; ++f)
        {
            if (f_color != color_mas[f].color) 
            {
                temp = f;
                f_color = color_mas[f].color;
            }
            full_counter += (2*(f - temp) + 1 - color_counter[f_color])*color_mas[f].m;
        }
        if (j > 1)
        {
            qsort(color_mas, i*j, sizeof(color_index), comp_n);
            f_color = color_mas[0].color;
            temp = 0;
            for (ll f = 0; f < i*j; ++f)
            {
                if (f_color != color_mas[f].color) 
                {
                    temp = f;
                    f_color = color_mas[f].color;
                }
                full_counter += (2*(f - temp) + 1 - color_counter[f_color])*color_mas[f].n;
            }
        }
    }else if (j > 1)
    {
        qsort(color_mas, i*j, sizeof(color_index), comp_n);
        f_color = color_mas[0].color;
        temp = 0;
        for (ll f = 0; f < i*j; ++f)
        {
            if (f_color != color_mas[f].color) 
            {
                temp = f;
                f_color = color_mas[f].color;
            }
            full_counter += (2*(f - temp) + 1 - color_counter[f_color])*color_mas[f].n;
        }
    }
    printf("%lld", full_counter);
    return 0;
}