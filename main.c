#include "stackchar.h"
#include "stacknode.h"
#include "functions.h"
#include "tree.h"

#define NMAX 100

/*Умножение переменной на сумму заменить на сумму произведений*/

int main(void) {
    char c, mas[NMAX];

    StackChar * stackchar = (StackChar*) malloc(sizeof(StackChar));

    PolishNote(c, &mas[0], stackchar);
    
    int size = SizeMas(mas);
    printf("%d\n", size);
    PrintMas(&mas[0], size);

    StackNode * stacknode = (StackNode*) malloc(sizeof(StackNode));
    BuildTree(size, stacknode, mas);

    TreeNode* tree = PopNode(stacknode);
    PrintTree(tree);

    DoTask(tree);
    PrintTree(tree);
    return 0;
}

