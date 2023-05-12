#ifndef _STACKNODEH_
#define _STACKNODEH_

#include <stdio.h>
#include "tree.h"

typedef struct ListNode {
    TreeNode* noda;
    struct ListNode * next;
} ListNode;

typedef struct StackNode {
    ListNode * front;
    int size;
} StackNode;

void PushNode(StackNode * cur, TreeNode* data) {
    ListNode * tmp = (ListNode*) malloc(sizeof(ListNode));
    tmp->noda = data;
    tmp->next = cur->front;
    cur->front = tmp;
    cur->size = cur->size + 1;
}

TreeNode* PopNode(StackNode * cur) {
    ListNode *out = cur->front;
    TreeNode* buf;
    if (cur != NULL) {
        buf = out->noda;
        cur->front= out->next;
        cur->size = cur->size - 1;
        free(out);
    }
    return buf;
}

TreeNode* PeekNode(StackNode* stack) {
    return stack->front->noda;
}

int IsEmptyNode(StackNode* stack) {
    return stack->front == NULL;
}

int IsSizeNode(StackNode * cur) {
    return cur->size;
}

#endif