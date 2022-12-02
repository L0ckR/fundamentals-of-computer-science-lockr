/* Лабраторная работа 9.
  Студент гр.08-108 Далгат Ибрагимов
*/
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h> 
 
int MAX(int a, int b){
    if (a > b){
        return a;
    }else{
        return b;
    }
}

int MIN(int a, int b){
    if (a < b){
        return a;
    }else{
        return b;
    }
}

int sign(int a) 
{ 
    if (a > 0){ 
        return 1; 
    } 
 
    if (a == 0){ 
        return 0; 
    } 
 
    return -1; 
} 
typedef struct {
    int i, j, l;
} State;
 
State state_for_ex_k(State a, int ex_k){
    State res = {abs(abs(MAX(a.i*(ex_k+5),(a.j*(ex_k+6)))) - abs(MIN((a.j*(ex_k+7)), (a.l*(ex_k+8))))) % 20, (abs((3 - sign(a.i - a.j))*abs(MIN(MIN((a.i*a.l+5),(a.j*a.l-3)),(a.i*a.j+6)))))%25 - 7, abs(a.i)%10 + abs(a.j)%10 + abs(a.l)%10};
    return res;
}

bool is_in_func(int k, State a){
    if ((a.i >= 5 && a.i <= 15) && (a.j <= -5 && a.j >= -15)){ 
       return true;
    }
    return false;
}

int main() 
{ 
    bool flag = true;
    State a = {10, 20, -1};
    for (int k = 0; k <= 50; k++){ 
        printf("%u) %d %d %d \n", k, a.i, a.j, a.l);
        if (is_in_func(k, a)){ 
            printf("got it in %d = count of attempts, %d - i coord, %d - j coord, %d - l variable \n", k, a.i, a.j, a.l); 
            flag = false;
            break; 
        } 
        a = state_for_ex_k(a, k);
    }
    if (flag){
        printf("missed. %d - i coord, %d - j coord, %d - l variable \n", a.i, a.j, a.l);
    }
}
