#include "../headers/header.h"

void insert(queue* buffer, double elem){

    int buffer_length = size(buffer);

    if (size(buffer) == 1){
        double cmp = pop(buffer);
        if (cmp >= elem){
            push(buffer, elem);
            push(buffer, cmp);
        } else {
            push(buffer, cmp);
            push(buffer, elem);
        }
    } else {
        double left = pop(buffer);
        double right = pop(buffer);
        int position = 2;
        for (int i = 0; i <= size(buffer); ++i){
            if (elem <= left){
                push(buffer, elem);
                push(buffer, left);
                push(buffer, right);
                for (int j = position; j < size(buffer) - 1; ++j){
                    double tmp = pop(buffer);
                    push(buffer, tmp);
                }
                break;
            } else if (elem > left && elem <= right){
                push(buffer, left);
                push(buffer, elem);
                push(buffer, right);
                for (int j = position; j < size(buffer) - 1; ++j){
                    double tmp = pop(buffer);
                    push(buffer, tmp);
                    printQ(buffer);
                }
                break;
            } else {
                push(buffer, left);
                if (position == buffer_length){
                    push(buffer, right);
                    push(buffer, elem);
                    printQ(buffer);
                    break;
                } else {
                    left = right;
                    right = pop(buffer);
                    position++;
                }
            }
        }
    }

}

void sort(queue* q){

    int sorted = 1;
    if (sorted == size(q)){ return; }

    queue buffer; 
    create(&buffer);

    while (sorted < size(q)){
    
        for (int i = 0; i < sorted; ++i){
            double tmp = pop(q);
            push(&buffer, tmp);
        }

        double elem = pop(q);
        insert(&buffer, elem);

        while (!is_empty(q)){
            double tmp = pop(q);
            push(&buffer, tmp);
        }

        while (!is_empty(&buffer)){
            double tmp = pop(&buffer);
            push(q, tmp);
        }
        
        sorted++;

    }
    destroy(&buffer);

}
