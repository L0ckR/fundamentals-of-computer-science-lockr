#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
typedef unsigned long long int ullint;

ullint scan2(){
    ullint i = 0;
    for (char c = getchar(); c != ' ' && c != '\n'; c = getchar()) {
        if(c == '0' || c == '1') {
            i *= 2;         
            i += (c - '0');         
        }
    }
    return i;
}

ullint find_k(ullint str1, ullint str2){
    while (str2%2 != 1){
        str2 >>= 1;
        str1 >>= 1;
    }
    ullint k = 0;
    while (str1 != 0){
        if (str1%2 == 1){
            return k;
        }
        str1 >>= 1;
        k++;
    }
    return k;
}


int main()
{
    ullint t;
    scanf("%llu", &t);
    ullint k[t];
    getchar();
    for (ullint i = 0; i < t; i++){
        ullint str1 = scan2();
        ullint str2 = scan2();
        k[i] = find_k(str1, str2);
    }
    for ( ullint i = 0; i < t; i++){
        printf("%llu\n", k[i]);
    }
    return 0;
}