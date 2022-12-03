#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
typedef unsigned int uint;

uint scanstr2(){
    uint i = 0;
    for (char c = getchar(); c != ' ' && c != '\n'; c = getchar()) {
        if(c == '0'){
            i++;
        }else{
            i = 0;
        }
    }
    return i;
}


int main()
{
    unsigned char t;
    scanf("%hhu", &t);
    getchar();
    for (uint z = 0; z < t; z++){
        uint i_k[10000];
        uint i = 0;
        uint s_i = 0;
        uint counter = 0;
        for (char c = getchar(); c != ' ' && c != '\n'; c = getchar()) {
            if(c == '0'){
                i++;
            }else{
                if (i != 0){
                    i_k[counter] = i;
                    i = 0;
                    counter++;
                }
                i_k[counter] = i;
                counter++;
            }
        }
        if (i != 0){
            i_k[counter] = i;
        }else{
            counter--;
        }
        s_i = scanstr2();
        while (s_i > i_k[counter]){
            if (i_k[counter] != 0){
                s_i -= i_k[counter];
            }else{
                s_i--;
            }
            counter--;
        }
        printf("%u\n", i_k[counter] - s_i);
    }
    return 0;
}