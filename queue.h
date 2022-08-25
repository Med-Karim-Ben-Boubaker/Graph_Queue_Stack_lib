#ifndef __QUEUE_H__
#define __QUEUE_H__


struct queue {
  int* items;
  int front;
  int rear;
  int size;
};

struct queue* createQueue(int size);
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void displayQueue(struct queue* q);
int isEmptyQueue(struct queue* q);
void resizeQueue(struct queue* q, int newSize);
void resetQueue(struct queue* q);
#endif