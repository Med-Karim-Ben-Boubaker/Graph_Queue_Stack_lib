#ifndef __STACK_H__
#define __STACK_H__

struct stack {
    int* items;
    int head;
    int size;
};

struct stack* createStack(int size);
void push(struct stack* stack, int);
int pop(struct stack* stack);
void displayStack(struct stack* stack);
int isEmptyStack(struct stack* satck);
void resetStack(struct stack* stack);
void resizeStack(struct stack* stack, int newSize);

#endif