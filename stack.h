#ifndef __STACK_H__
#define __STACK_H__
#define SIZE 40

struct stack {
    int items[SIZE];
    int head;
};

struct stack* createStack();
void push(struct stack* stack, int);
int pop(struct stack* stack);
void displayStack(struct stack* stack);
int isEmptyStack(struct stack* satck);
void printStack(struct stack* stack);

#endif