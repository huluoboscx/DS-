#include <iostream>
using namespace std;
struct Queue {
    int front, rear;
    int capacity;
    int* array;
};

Queue* createQueue(int capacity) {
    Queue* queue = new Queue;
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = new int[queue->capacity];
    return queue;
}

// �ж϶����Ƿ�Ϊ��
bool isQueueEmpty(Queue* queue) {
    return queue->front == -1;
}

// �ж϶����Ƿ�����
bool isQueueFull(Queue* queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}

// ���
void enqueue(Queue* queue, int item) {
    if (isQueueFull(queue)) {
        return;
    }
    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = 0;
    }
    else {
        queue->rear = (queue->rear + 1) % queue->capacity;
    }
    queue->array[queue->rear] = item;
}

// ����
int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        return -1;
    }
    int item = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    }
    else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return item;
}

// ��ȡ����ͷԪ��
int getFront(Queue* queue) {
    if (isQueueEmpty(queue)) {
        return -1;
    }
    return queue->array[queue->front];
}
