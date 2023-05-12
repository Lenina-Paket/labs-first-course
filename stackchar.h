#ifndef _STACKH_
#define _STACKH_

#include <stdio.h>
#include <stdlib.h>

typedef struct ListChar {
    char data;
    struct ListChar * next;
} ListChar;

typedef struct StackChar {
    struct ListChar * front;
    int size;
} StackChar;


void PushChar(StackChar * cur, char data) {
    ListChar * tmp = (struct ListChar*) malloc(sizeof(struct ListChar));
    tmp->data = data;
    tmp->next = cur->front;
    cur->front = tmp;
    cur->size = cur->size + 1;
}

char PopChar(StackChar * cur) {
    ListChar *out = cur->front;
    char buf;
    if (cur != NULL) {
        buf = out->data;
        cur->front = out->next;
        cur->size = cur->size - 1;
        free(out);

    }
    return buf;
}

void PrintStackChar(StackChar * cur) {
    ListChar * node = cur->front;
    printf("Stack Elements\n");
    while (node != NULL) {
        printf("%c ", node->data);
        node = node->next;
    }
    printf("\n");
}

char PeekChar(StackChar* stack) {
    if (stack->front == NULL) {
        return -1; 
    } else {
        return stack->front->data;
    }
}

int IsEmptyChar(StackChar* stack) {
    return stack->front == NULL;
}

int IsSizeChar(StackChar * cur) {
    return cur->size;
}

#endif
