#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define DBL_LOG102 (3.010299956639811952E-1)
#define INT_WIDTH (32)
#define N (((int) (DBL_LOG102 * (INT_WIDTH - 1) + 1))-1)

typedef enum
{
    OUTSIDE,
    WRONG_WORD_NO
} Conditions;

void check_poryadok(){
    Conditions condition = OUTSIDE;
    for (int ch = getchar(); ch != EOF; ch = getchar())
    {
        switch (condition){
            case OUTSIDE:
                if (isdigit(ch))
                {
                    int temp = ch;
                    int k = 0;
                    while (k <= 10){
                        k++;
                        ch = getchar();
                        if (isdigit(ch)){
                            if (ch > temp){
                                condition = WRONG_WORD_NO;
                                printf("NO");
                                goto wwn;
                            }
                        }else if (ch == ' ' || ch == EOF){
                            break;
                        }
                    }
                    if (ch == EOF || ch == ' '){
                        printf("YES");
                        putchar(ch);
                        continue;
                    }
                }else if ( ch == '-')
                {
                    condition = OUTSIDE;
                    continue;
                }
            wwn:case WRONG_WORD_NO:
                while (ch != ' ' && ch != EOF)
                {
                    ch = getchar();
                }
                if (ch == EOF)
                {
                    putchar(ch);
                    break;
                }
                putchar(ch);
                condition = OUTSIDE;
                continue;
        }
    }
}


int main(){
    check_poryadok();
    return 0;
}
