#include <stdio.h>
#include <stdlib.h>

typedef struct QNode {
    int data;
    struct QNode * next;
    struct QNode * prev;
} QNode;

typedef struct MyQueue {
    struct QNode * front;
    struct QNode * back;
    int size;
} MyQueue;

// Вспомогательная функция для выделения нового узла queue
QNode * getQNode(int data, QNode * prev) {
    // выделяем новый узел в куче
    QNode * cur = (QNode * ) malloc(sizeof(QNode));
    
    if (cur == NULL) {
        return NULL;
    }
    
    cur->data = data;
    cur->next = NULL;
    cur->prev = prev;
    return cur;
}

MyQueue * getMyQueue() {
    MyQueue * cur = (MyQueue * ) malloc(sizeof(MyQueue));
    if (cur == NULL) {
        return NULL;
    }
    cur->front = NULL;
    cur->back = NULL;
    return cur;
}

void enqueue(MyQueue * cur, int data) {
    QNode * node = getQNode(data, cur->back);
    if (cur->front == NULL) {
        cur->front = node;
        cur->size = 1;
    } else {
        cur->back->next = node;
        cur->size = cur->size + 1;
    }
    cur->back = node;
}

int isEmpty(MyQueue * cur) {
    if (cur->size == 0) {
        return 1;
    } else {
        return 0;
    }
}

int peek(MyQueue * cur) {
    if (isEmpty(cur) == 1) {
        printf("\n Empty Queue");
        return -1;
    } else {
        return cur->front->data;
    }
}

int isSize(MyQueue * cur) {
    return cur->size;
}


int dequeue(MyQueue * cur) {
    if (isEmpty(cur) == 1) {
        return -1;
    }
    else {
        int data = peek(cur);
        QNode * temp = cur->front;
        if (isSize(cur) == 1) {
            cur->back = NULL;
            cur->front = NULL;
        } else {
            cur->front = cur->front->next;
            cur->front->prev = NULL;
        }
        cur->size--;
        return data;
    }
}

void printQdata(MyQueue * cur) {
    QNode * node = cur->front;
    printf("Queue Element\n");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    int a, n;
    MyQueue * q = getMyQueue();
    printf("Enter a number of elements: \n");
    scanf("%d", &n);
    printf("Welcome, elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        enqueue(q, a);
    }
    dequeue(q);
    printQdata(q);
    printf("Size : %d\n", isSize(q));
    
    int i = 0, buf, mas[q->size];
    int len = q->size;
    QNode * temp = q->front;
    while (temp != NULL) {
        mas[i++] = temp->data;
        temp = temp->next;
    }
    //printf("%d\n", mas[3]);
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (mas[i] >= mas[j]) {
                buf = mas[i];
                mas[i] = mas[j];
                mas[j] = buf;
            }
        }
    }
    for (int i = 0; i < len; i++) {
        printf("%d ", mas[i]);
    }
      return 0;
}
