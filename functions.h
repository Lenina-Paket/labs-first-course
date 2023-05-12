#ifndef _FUNCTIONSH_
#define _FUNCTIONSH_
#include <stdio.h>
#include "stackchar.h"
#include "stacknode.h"
#include "tree.h"

int IsOperator(char a) {
    if ((a == '+') || (a == '-') || (a == '*') || (a == '/')) return 1;
    return 0;
}

int IsDigit(char a) {
    if ((a >= '0') && (a <= '9')) return 1;
    return 0;
}

int IsVariable(char a) {
    if ((a >= 'a') && (a <= 'z')) return 1;
    return 0;
}

int SizeMas(char *mas) {
    int size = 0;
    while (*mas) {
        size++;
        mas++;
    }
    return size;
}
void PrintMas(char *mas, int n) {
    printf("Array Elements\n");
    for (int i = 0; i < n; i++) {
        printf("%c", *mas);
        mas = mas + 1;
    }
    printf("\n");
}

void PolishNote(char c, char *masElem, StackChar *stck) {
    c = getchar();
    while (c != '\n') {
        if (((c >= '0') && (c <= '9')) || (('a' <= c) && (c <= 'z'))) {
            *masElem = c;
            masElem = masElem + 1;
        } else {
            if (c == '*' || c == '/' || c == '(') {
                PushChar(stck, c);
            }
            if (c == '-' || c == '+') {
                if ((PeekChar(stck) != '*') && (PeekChar(stck) != '/')) {
                    PushChar(stck, c);
                } else {
                    while (not(IsEmptyChar(stck))) {
                        *masElem = PopChar(stck);
                        masElem = masElem + 1;
                    }
                    PushChar(stck, c);
                }
            }
            if (c == ')') {
                if (c != '(') {
                     *masElem = PopChar(stck);
                    masElem = masElem + 1;
                }
                PopChar(stck); 
            }
        }

        c = getchar();
    }
    while (not(IsEmptyChar(stck))) {
        *masElem = PopChar(stck);
        masElem = masElem + 1;
    }
}

TreeNode* BuildTree(int len, StackNode *stk, char *mas) {
    if (len - 1 == 0) {
        return NULL;
    }
    for (int i = 0; i < len; ++i) {
        if (IsOperator(mas[i])) {
            TreeNode *x = PeekNode(stk);
            PopNode(stk);
            TreeNode *y = PeekNode(stk);
            PopNode(stk);
            TreeNode *node = CreateTree(mas[i]);
            node->left = y;
            node->right = x;
            PushNode(stk, node);

        } else {
            TreeNode *node = CreateTree(mas[i]);
            node->value = mas[i];
            PushNode(stk, node);
        }
    }
    return PeekNode(stk);
}

void DoTask(TreeNode *node) {
    char buf1, buf2, var;
    if (node == NULL) {
        return;
    }
    DoTask(node->left);
    DoTask(node->right);
    if (IsOperator(node->value)) {
        if (node->value == '*') {
            if (node->left->value == '+') {
                if (IsVariable(node->right->value)) {
                    var = node->right->value; 
                    node->value = '+';

                    node->left->value = '*';
                    node->right->value = '*';

                    if (node->left->left != NULL) {
                        buf1 = node->left->right->value;
                        node->left->right->value = var;
                    }
                    TreeNode * new1 = CreateTree(var);
                    node->right->left = new1;

                    TreeNode * new2 = CreateTree(buf1);
                    node->right->right = new2;
                }
            }
            if (node->right->value == '+') {
                if (IsVariable(node->left->value)) {
                    var = node->left->value; 
                    node->value = '+';

                    node->left->value = '*';
                    node->right->value = '*';

                    if (node->right->right != NULL) {
                        buf2 = node->right->left->value;
                        node->right->left->value = var;
                    }

                    TreeNode* new1 = CreateTree(var);
                    node->left->left = new1;

            
                    TreeNode * new2 = CreateTree(buf2);
                    node->left->right= new2;
            }
        }
    }

}
}
#endif