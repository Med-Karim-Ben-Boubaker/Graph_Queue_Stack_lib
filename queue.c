#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Create a queue
struct queue* createQueue(int size) {
  struct queue* q = malloc(sizeof(struct queue));
  q->items = (int*)malloc(size * sizeof(int));
  q->front = -1;
  q->rear = -1;
  q->size = size;
  return q;
}

// Check if the queue is empty
int isEmptyQueue(struct queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

// Adding elements into queue
void enqueue(struct queue* q, int value) {
  if (q->rear == q->size - 1)
    printf("Queue Overflow \n");
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

// Removing elements from queue
int dequeue(struct queue* q) {
  int item;
  if (isEmptyQueue(q)) {
    printf("Queue Underflow \n");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      printf("Resetting queue \n");
      q->front = q->rear = -1;
    }
  }
  return item;
}

// Print the queue
void displayQueue(struct queue* q) {
  int i = q->front;

  if (isEmptyQueue(q)) {
    printf("Queue is empty \n");
  } else {
    printf("Queue Items: ");
    for (i = q->front; i < q->rear + 1; i++) {
      printf("%d, ", q->items[i]);
    }
    printf("\n");
  }
}

//Resetting the queue
void resetQueue(struct queue* q){
  if(isEmptyQueue((q))){
    printf("Queue is empty, resetting is not possible");
    return;
  }

  q->front = q->rear = -1;
}

void resizeQueue(struct queue* q, int newSize){
  q->size = newSize;
  q->items = (int*) realloc (q->items, newSize);
}