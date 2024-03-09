#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int priority[MAX_SIZE];  
    int front;
    int rear;
} PriorityQueue;

void init(PriorityQueue *pq) {
    pq->front = -1;
    pq->rear = -1;
}

int isEmpty(PriorityQueue *pq) {
    return (pq->front == -1);
}

int isFull(PriorityQueue *pq) {
    return ((pq->rear + 1) % MAX_SIZE == pq->front); // increasing the array index.
}

//function to insert an element from front
void enqueueFront(PriorityQueue *pq, int item, int priority) {
    if (isFull(pq)) {
        printf("Queue is full.\n");
        return;
    }

    if (isEmpty(pq)) {
        pq->front = pq->rear = 0;
    } else {
        pq->front = (pq->front - 1 + MAX_SIZE) % MAX_SIZE;  //decreasing the array index by 1 and pointing as front.
    }

    pq->data[pq->front] = item;
    pq->priority[pq->front] = priority;
}

// function to insert element at front
void enqueueRear(PriorityQueue *pq, int item, int priority) {
    if (isFull(pq)) {
        printf("Queue is full.\n");
        return;
    }

    if (isEmpty(pq)) {
        pq->front = pq->rear = 0;
    } else {
        pq->rear = (pq->rear + 1) % MAX_SIZE;
    }

    pq->data[pq->rear] = item;
    pq->priority[pq->rear] = priority;
}

//function to delete an element from front.
int dequeueFront(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty.\n");
        return -1;
    }

    int item = pq->data[pq->front];
    int priority = pq->priority[pq->front];

    if (pq->front == pq->rear) {
        pq->front = pq->rear = -1;
    } else {
        pq->front = (pq->front + 1) % MAX_SIZE;
    }

    return item;
}

//function to delete an element from rear
int dequeueRear(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty.\n");
        return -1;
    }

    int item = pq->data[pq->rear];
    int priority = pq->priority[pq->rear];

    if (pq->front == pq->rear) {
        pq->front = pq->rear = -1;
    } else {
        pq->rear = (pq->rear - 1 + MAX_SIZE) % MAX_SIZE;  //decreasing the array index.
    }

    return item;
}

void display(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Priority Queue:\n");
    int i = pq->front;
    do {
        printf("%d (Priority: %d)\n", pq->data[i], pq->priority[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (pq->rear + 1) % MAX_SIZE);
}

int main() {
    PriorityQueue pq;
    init(&pq);

    enqueueFront(&pq, 10, 1);
    enqueueRear(&pq, 20, 2);
    enqueueFront(&pq, 30, 3);
    enqueueRear(&pq, 40, 4);

    display(&pq);

    dequeueFront(&pq);
    dequeueRear(&pq);

    display(&pq);

    return 0;
}