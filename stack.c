#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//Creating the stack
struct stack* createStack(int size){
    struct stack* stack = malloc(sizeof(struct stack));
    stack->head = -1;
    stack->items = (int*)malloc(size * sizeof(int)); 
    stack->size = size;
    return stack;
}

//Adding an element to the stack
void push(struct stack* stack, int value) {
    if(stack->head == stack->size - 1) {
        printf("StackOverflow \n");
        return;
    }

    stack->head++;
    stack->items[stack->head] = value;
}

//Removing element from the stack
int pop(struct stack* stack){
    if(isEmptyStack(stack)){
        printf("StackUnderflow");
        return -1;
    }


    int removed_value;
    removed_value = stack->items[stack->head];
    stack->head--;
    return removed_value;
}

//Checking if the stack is empty
int isEmptyStack(struct stack* stack){
    if(stack->head == -1) return 1;
    return 0;
}

//Showing stack elements
void printStack(struct stack* stack){
    if(isEmptyStack(stack)){
        printf("Stack is empty");
        return;
    }

    printf("Stack Items: ");
    int i;
    for(i=stack->head; i>=0; i--){
        printf("%d,", stack->items[i]);
    }
    printf("\n");
}

//Resetting a stack
void resetStack(struct stack* stack){
    if(isEmptyStack(stack)) {
        printf("Stack is empty, you cannot reset it");
        return;
    }

    stack->head = -1;
}

//Resize the Stack
void resizeStack(struct stack* stack, int newSize){
    stack->size = newSize;
    stack->items = (int*) realloc (stack->items, newSize);
}
