/* Задание на +0.5
Представьте себе таблицу размера N x N. В i-ой строке и j-ом столбце записано число i*j, где i, j от 1 до n.
Задано целое положительно число x. Необходимо отыскать сколько раз число x встретится в таблице.
Алгоритм с временем O(N^2) НЕПРИЕМЛЕМ. Это означает, что строить таблицу явно ЗАПРЕЩЕНО.
Перебирать все N^2 элементов таблицы ЗАПРЕЩЕНО.
*/

#include <stdio.h>  
#include <stdlib.h>

typedef unsigned uint;

uint count(uint n, uint x)
{
    uint counter = 0;
    if (x <= n*n)
    {
        if (x >= n)
        {
            for (int i=1; i <= n; i++)
            {
                if ((x%i == 0)&&(x/i <= n))
                {
                    counter++;
                }
            }
        }
        else
        {
            for (int i=1; i <= x; i++)
            {
                if ((x%i == 0)&&(x/i <= n))
                {
                    counter++;
                }
            }
        }
        
        
    }
    return counter;
 }

int main() 
{ 
    uint x, n;
    scanf("%u %u", &n, &x);
    printf("%u", count(n, x));
    return 0;
}