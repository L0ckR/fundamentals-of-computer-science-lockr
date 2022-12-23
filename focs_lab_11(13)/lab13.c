#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#define UINT_WIDTH (32)
#define MAX_ALPHABET ((UINT_MAX >> (UINT_WIDTH - (26U))) + 2)

typedef enum
{
    OUTSIDE,
    INSIDE
} Conditions;

typedef unsigned int uint;

uint char_to_set(char c)
{
    c = tolower(c);
    if(c < 'a' || c > 'z')
    {
        return 0;
    }else{
        return 1u<<(c-'a');
    }
}

void check_neighboured(){
    bool flag = false;
    uint set_2;
    uint set_1 = MAX_ALPHABET;
    Conditions condition = OUTSIDE;
    for (char ch = getchar(); ch != EOF; ch = getchar())
    {
        switch(condition)
        {
            case OUTSIDE:
                if (isalpha(ch) || ch == ',')
                {
                    putchar(ch);
                    set_2 = char_to_set(ch);
                    condition = INSIDE;
                    continue;
                } else
                {
                    putchar(ch);
                    continue;
                }
            case INSIDE:
                if (isalpha(ch) || ch == ',')
                {
                    putchar(ch);
                    set_2 = set_2 | char_to_set(ch);
                    continue;
                } else if(isspace(ch))
                {
                    putchar(ch);
                    if ((set_1 == set_2)&&(set_1 != MAX_ALPHABET)){
                        flag = true;
                    }
                    set_1 = set_2;
                    condition = OUTSIDE;
                    continue;
                } else
                {
                    putchar(ch);
                    continue;
                }    
        }
        if ((set_1 == set_2)&&(set_1 != 67108864)){
            flag = true;
        }
    }
    if (flag)
    {
        printf("\n\n\nYEEEES");
    } else{
        printf("\n\n\nNO");
    }
}


int main()
{
    check_neighboured();
    return 0;
}
