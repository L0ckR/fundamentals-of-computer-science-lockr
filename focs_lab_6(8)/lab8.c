/* Лабраторная работа 8.
 * Студент гр.08-108 Далгат Ибрагимов*/

#include <stdio.h>

int main() {
    int x , y, i;
    printf("Первое число: ");
    scanf("%d",&x);
    printf("Второе число: ");
    scanf("%d",&y);
    printf("Сложение (1), вычитание (2), умножение (3) или деление (4): ");
    scanf("%d",&i);
    if(i==1)
        printf("%d + %d = %d \n",x,y,x+y);
    if(i==2)
        printf("%d - %d = %d \n",x,y,x-y);
    if(i==3){
        long int res;
        res=x*y;
        printf("%d * %d = %d \n",x,y,res);
    }
    if(i==4){
        float x1,y1,res;
        x1=x;
        y1=y;
        res=x1/y1;
        printf("%f./%f. = %f \n",x1,y1,res);
    }
    return 0;
}
