#include "../headers/header.h"

void print_result(queue* q){
    printQ(q);
    double elem = pop(q);
    bool is_sorted = true;
    while (!is_empty(q)){
        double next_elem = pop(q);
        if (elem > next_elem){
            is_sorted = false;
        }
        elem = next_elem;
    }
    if (is_sorted){
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

int main(){

    queue q;
    create(&q);

    int m;
    printf("Input number of elements\n");
    scanf("%d", &m);
    printf("Enter %d values\n", m);
    for (int i = 0; i < m; ++i){
        double n;
        scanf("%lf", &n);
        push(&q, n);
    }
    printQ(&q);
    if (!is_empty(&q)){
        sort(&q);
        print_result(&q);
    } else {
        printf("Empty queue\n");
    }
    destroy(&q);

}
