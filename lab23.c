#include <stdio.h>
#include <stdlib.h>

struct tree_node {
    int key;
    struct tree_node *child;
    struct tree_node *sibling;
    struct tree_node *parent;
};
typedef struct tree_node node;

node *create_tree(int value) {
    node *tree = (node *) malloc(sizeof(node));
    tree->key = value;
    tree->child = NULL;
    tree->sibling = NULL;
    tree->parent = NULL;
    return tree;
}

node *find_node(node* tree, int value) {
    if (tree == NULL) {
        return NULL;
    }
    if (tree->key == value) {
        return tree;
    }
    node* cur = NULL;
    if (tree->child) {
        cur = find_node(tree->child, value);
        if (cur != NULL) {
            return cur;
        }
    }
    if (tree->sibling) {
        cur = find_node(tree->sibling, value);
        if (cur != NULL) {
            return cur;
        }
    }
}

void add_node(node* tree, int cur, int value) {
    node *res = find_node(tree, cur);
    if (res == NULL) {
        return;
    }
    node *res_parent = res;
    if (res->child == NULL) {
        res->child = create_tree(value);
        res->child->parent = res;
        return;
    }
    res = res->child;
    while (res->sibling != NULL) {
        res = res->sibling;
    }
    res->sibling = create_tree(value);
    res->sibling->parent = res_parent;
}

void delete_node(node* tree, int value) {
    if (tree != NULL) {
        if (tree->child != NULL) {
            if (tree->child->key == value) {
                node *prev = tree->child;
                tree->child = tree->child->sibling;
                free(prev);
                prev = NULL;
            } else {
                delete_node(tree->child, value);
             }
        }
        if (tree->sibling != NULL) {
            if (tree->sibling->key == value) {
                node *prev = tree->sibling;
                tree->sibling = tree->sibling->sibling;
                free(prev);
                prev = NULL;
            } else {
                delete_node(tree->sibling, value);
            }
        }
    }
}

void delete_undertree(node *tree) {
    if (tree == NULL) {
        return;
    } else {
        if (tree->child) {
            tree = tree->child;
        } else {
            return;
        }
        if (tree->child) {
            delete_undertree(tree->child);
        }
        node *next = tree;
        node *prev = NULL;
        while (next->sibling) {
            prev = next;
            next = next->sibling;
            if (next->child) {
                delete_undertree(next->child);
            }
            free(prev);
        }
        free(next);
    }
}

void delete_tree(node *tree, int value) {
    node *res = find_node(tree, value);
    delete_undertree(res);
    delete_node(tree, value);
}


void tree_show(node *cur, int deep) {
    if (cur != NULL) {
        for (int i = 0; i < deep; i++) {
            printf("    ");
        }
        printf("%d\n", cur->key);
        if (cur->child != NULL) {
            tree_show(cur->child, deep + 1);
        }
        tree_show(cur->sibling, deep);
    }
}

void tree_print(node *t) {
    tree_show(t, 0);
}


void tree_destroy(node *t) {
    if (t != NULL) {
        if (t->child != NULL) {
            tree_destroy(t->child);
        }
        if (t->sibling != NULL) {
            tree_destroy(t->sibling);
        }
    }
    free(t);
}

int check(node *t) {
    if (t != NULL) {
        while (t->child != NULL) {
            t = t->child;
            if (t->sibling != NULL) {
                return 0;
            }
        }
        return 1;
    } else {
        return 1;
    }
}

int main() {
    int root, flag = 1, cnt = 0;
    node *t = NULL;
    while (flag) {
        printf("1. add root, 2. add node, 3. delete node, 4.check task, 5. print tree, 0. quit\n");
        int select, value, cur;
        scanf("%d", &select);
        switch (select) {
            case 1:
                printf("add root: ");
                scanf("%d", &root);
                t = create_tree(root);
                break;
            case 2:
                printf("enter node and value: ");
                scanf("%d%d", &cur, &value);
                if (t == NULL) {
                    printf("tree is empty!\n");
                } else {
                    add_node(t, cur, value);
                }
                break;
            case 3:
                printf("enter value: ");
                scanf("%d", &value);
                if (t == NULL) {
                    printf("tree is empty!\n");
                } else { 
                    if (value != root) {
                        delete_tree(t, value);
                    } else {
                        printf("I forbid you to remove the root\n");
                    }
                }
                break;
            case 4:
                if (check(t)) {
                    printf("YES\n");
                } else {
                    printf("NO\n");
                }
                break;
            case 5:
                if (t == NULL) {
                    printf("tree is empty!\n");
                } else {
                    tree_print(t);
                }
                break;
            case 0:
                flag = 0;
                break;
        }
    }
    tree_destroy(t);
    return 0;
}