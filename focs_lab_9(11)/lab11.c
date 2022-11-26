#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

typedef enum
{
    OUTSIDE,
    INSIDE_0,
    INSIDE_1,
    INSIDE_1_1,
    WRONG_WORD
} Conditions;


void fd_ispaniol(char fd){
    switch (fd){
        case '2': 
            printf("veinti"); 
            return;
        case '3':  
            printf("treinta y "); 
            return;
        case '4':
            printf("cuarenta y "); 
            return;
        case '5': 
            printf("cincuenta y "); 
            return;
        case '6': 
            printf("sesenta y "); 
            return;
        case '7': 
            printf("setenta y "); 
            return;
    }
}

void sd_ispaniol(char sd){
    switch (sd){
        case '1': 
            printf("uno\n");
            return;
        case '2': 
            printf("dos\n"); 
            return;
        case '3': 
            printf("tres\n"); 
            return;
        case '4': 
            printf("cuatro\n");
             return;
        case '5': 
            printf("cinco\n"); 
            return;
        case '6': 
            printf("seis\n"); 
            return;
        case '7': 
            printf("siete\n"); 
            return;
    }
}

void to_ispaniol(char fd, char sd){
    if (sd == '0'){
        switch (fd){
            case '2': 
                printf("veinte\n");
                return;
            case '3': 
                printf("treinta\n");
                return;
            case '4': 
                printf("cuarenta\n");
                return;
            case '5': 
                printf("cincuenta\n");
                return;
            case '6': 
                printf("sesenta\n");
                return;
            case '7': 
                printf("setenta\n");
                return;
        }
    }else{
        fd_ispaniol(fd);
        sd_ispaniol(sd);
    }
}


bool is_8iric(char ch){
    return isdigit(ch) && ch != '8' && ch != '9';
}

void ispanio(){
    char temp;
    bool minus = false;
    Conditions condition = OUTSIDE;
    for (char ch = getchar(); ch != EOF; ch = getchar())
    {
        switch (condition) 
        {
            case OUTSIDE:
                if (ch == '0' || ch == '-'){
                    minus = false;
                    if (ch == '-')
                    {
                        minus = true;
                    }
                    condition = INSIDE_0;
                    continue;
                } else if  (is_8iric(ch) && ch != '1')
                {
                    temp = ch;
                    condition = INSIDE_1;
                    continue;
                }else if  (ch == '1')
                {
                    condition = INSIDE_1_1;
                    temp = ch;
                    continue;
                }
            case WRONG_WORD:
                while (ch != ' ' && ch != EOF)
                {
                    ch = getchar();
                }
                if (ch == EOF)
                {
                    break;
                }
                condition = OUTSIDE;
            case INSIDE_0:
                if (ch == '0'){
                    continue;
                } else if  (is_8iric(ch) && ch != '1')
                {
                    temp = ch;
                    condition = INSIDE_1;
                    continue;
                }else if  (ch == '1')
                {
                    condition = INSIDE_1_1;
                    continue;
                }else if(ch == ' ')
                {
                    condition = OUTSIDE;
                    continue;
                }else
                {
                    condition = WRONG_WORD;
                    continue;
                }
            case INSIDE_1:
                if (ch == ' ') 
                {
                    condition = OUTSIDE;
                    continue;
                }else if (ch == EOF)
                {
                    break;
                }else if (is_8iric(ch) && getchar() == ' ')
                {
                    if (minus)
                    {
                        printf("menos ");
                    }
                    to_ispaniol(temp, ch);
                    condition = OUTSIDE;
                    continue;
                }else {
                    condition = WRONG_WORD;
                    continue;
                }
            case INSIDE_1_1:
                if (ch == ' ') 
                {
                    condition = OUTSIDE;
                    continue;
                }else if (ch == EOF)
                {
                    break;
                }else if (ch == '7' && getchar() == ' ')
                {
                    if (minus)
                    {
                        printf("menos ");
                    }
                    printf("diecisiete\n");
                    condition = OUTSIDE;
                    continue;
                }else {
                    condition = WRONG_WORD;
                    continue;
                }
        }

    }

}

int main(){
    ispanio();
    return 0;
}


