#include <stdio.h>
#include <stdbool.h>
typedef unsigned int uint;

#define N 100000


int main()
{
    unsigned char t;
    scanf("%hhu", &t);
    while(t--){
        char a[N] = {0};
        char b[N] = {0};
        uint k = N; 
        scanf("%s", a);
        while (a[k] != '0' && a[k] != '1'){
            k--;
        }
        uint lena = k;
        scanf("%s", b);
        k = N;
        while (b[k] != '0' && b[k] != '1'){
            k--;
        }
        uint lenb = k;
        while (b[k] != '1')
        {
            k--;
        }
        uint posb = lenb - k;
        k = lena - posb;
        while (a[k] != '1')
        {
            k--;
        }
        uint posa = lena - k;
        printf("%u\n", posa - posb);
    }
    return 0;
}