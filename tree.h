#ifndef _TREEH_
#define _TREEH_

#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    char value;
    struct tree* left;
    struct tree* right;
    //struct tree* parent; 
} TreeNode;

TreeNode* CreateTree(char value) {
    TreeNode* root_tree = (TreeNode*) malloc(sizeof(TreeNode));
    root_tree->value = value;
    //root_tree->parent = NULL;
    root_tree->left = root_tree->right = NULL;
    return root_tree;
}

void TreeVis(TreeNode *root, int count) {
    if (root != NULL) {
        for (int i = 0; i < count; ++i) {
            printf("|");
        }
    }
    printf("%c\n", root->value);
    if (root->left != NULL) {
        TreeVis(root->left, count + 1);
    }
    if (root->right != NULL) {
        TreeVis(root->right, count + 1);
    }
}

void PrintTree(TreeNode *root) {
    TreeVis(root, 0);
}

#endif
