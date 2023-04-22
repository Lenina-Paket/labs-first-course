#include <stdio.h>
#include <stdlib.h>
typedef enum {
    car,
    bus,
    train,
    tram,
    plane
} transp;

typedef struct List {
    transp data;
    struct List *next;
    struct List *prev;
} List;

List *Init (transp value) {
    List * cur = (List* )malloc(sizeof(List));
    cur->data = value;
    cur->next = NULL;
    cur->prev = NULL;
    return cur;
}

List *Add (List * cur, transp value, int number) {
    int count = 1;
    while (count != number) {
        if (cur->next != NULL) {
            cur = cur->next;
            count++;
        } else break;
    }

    List *tmp, *link;
    tmp = (List *)malloc(sizeof(List *));
    link = cur->next;
    cur->next = tmp;    
    tmp->data = value;
    tmp->next = link;
    tmp->prev = cur;
    if (link != NULL) {
        link->prev = tmp;
        return tmp;
    }
}
int Size(List *cur) {
    int counter = 0;
    while (cur != NULL) {
        counter++;
        cur = cur->next;
        
    }
    return counter;
}
void *Delete (List * cur, int number) {
    if (number <= Size(cur)) {
        int count = 1;
        while (count != number) {
            if (cur != NULL) {
                cur = cur->next;
                count++;
            } else break;
        }

        List *link_next, *link_prev;
        link_next = cur->next;
        link_prev = cur->prev;
        if (cur->prev != NULL) cur->prev->next = link_next;
        if (cur->next != NULL) cur->next->prev = link_prev;
        free(cur);
    }
}

void *Print(List *cur) {
    while (cur != NULL) {
        switch(cur->data) {
            case car:
                printf("car ");
                break;
            
            case bus:
                printf("bus ");
                break;
            
            case train:
                printf("train ");
                break;
            
            case tram:
                printf("tram ");
                break;
            case plane:
                printf("plane ");
                break;
        }
        cur = cur->next;
    }
    printf("\n");

}

List *Task(List *cur, int k) {
    if (k > Size(cur)) printf("Are you sure? It's impossible!\n");
    else {
        for (int i = 0; i < k; i++) {
            Delete(cur, Size(cur));
        }
    }
    return cur;
}

int main(void) {
    int k;
    List *lst = Init(car);
    Add(lst, bus, 1);
    Add(lst, plane, 2);
    Add(lst, train, 3);
    Add(lst, tram, 1);
    Print(lst);
    Delete(lst, 2);
    Print(lst);
    printf("Size of list: %d\n", Size(lst));
    printf("Enter a number of elements you want to delete:\n");
    scanf("%d", &k);
    Task(lst, k);
    //printf("Size of list: %d\n", Size(lst));
    Print(lst);
return 0;
}