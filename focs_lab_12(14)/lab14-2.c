#include <stdio.h>

const int maxn = 100;


void diag(int start, int end, int n, int m[]){
    for (int i = start; i <= end; i = i + (n + 1)){
        printf("%d ",m[i]);
    }
}

void left(int start, int end, int n, int m[]){
    for (int i = end - 1; i > end - end%n + start%n; i--){
        printf("%d ", m[i]);
    }
}

void reverse_left(int start, int end, int n, int m[]){
    for (int i = start + end%n - start%n; i >= start + 1; i--){
        printf("%d ", m[i]);
    }
}

void up(int start, int end, int n, int m[]){
    for (int i = end - end%n + start%n; i >= start + n; i = i - n){
        printf("%d ", m[i]);
    }
}

void reverse_up(int start, int end, int n, int m[]){
    for (int i = end - n; i > start + end%n - start%n; i = i - n){
        printf("%d ", m[i]);
    }
}


int main()
{
    int n;
    //  = 7;
    int m[maxn*maxn];
    // = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49};
    printf("MATRIX SIZE:");
    scanf("%d", &n);
    printf("MATRIX:");
    for (int k = 0; k != n*n; k++)
    {
        scanf("%d", m + k);
    }
    int start = 0;
    int end = n*n-1;
    diag(start, end, n, m);
    while (start != end){
        diag(start, end, n, m);
        left(start, end, n, m);
        up(start, end, n, m);
        start = start + (2*n + 1);
        end = end - (n + 2);
    }
    printf("%d ", m[start]);
    start = 0;
    end = n*n-1;
    while (start != end){
        if (start != 0){
            diag(start, end, n, m);
        }
        reverse_up(start, end, n, m);
        reverse_left(start, end, n, m);
        start = start + (n + 2);
        end = end - (2*n + 1);
    }
    printf("%d ", m[start]);
}