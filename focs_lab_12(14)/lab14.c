#include <stdio.h>

const int maxn = 100;
int start(int k,int j){
    if (k>=j){
        return (j-1);
    }else{
        return k;
    }
}

int end(int k, int i){
    if (k>=i){
        return (k-i+1);
    }else{
        return 0;
    }
}
void out(int i, int j, int m[]){
    for (int k = 0; k <= i - 1 + j - 1; k++)
    {
        if (k % 2 != 0){
            for (int j_f = end(k, i); j_f <= start(k, j); j_f++)
            {
                printf("%d ", m[(((i-1) - (k-j_f))*j + j_f)]);
            }
        }else{
            for (int j_f = start(k, j); j_f >= end(k, i); j_f--)
            {
                printf("%d ", m[(((i-1) - (k-j_f))*j + j_f)]);
            }
        }
    }
}
int main()
{
    int i, j;
    int m[maxn*maxn];
    scanf("%d %d", &i, &j);
    for (int k = 0; k != i*j; k++)
    {
        scanf("%d", m + k);
    }
    out(i, j, m);

}
