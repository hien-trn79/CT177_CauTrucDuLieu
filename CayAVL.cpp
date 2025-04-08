#include <stdio.h>
#include <malloc.h>

typedef int KeyType;
struct Node {
    KeyType Key;
    int Height;
    struct Node* Left;
    struct Node* Right;
};
typedef struct Node* AVLTree;

void makenullTree(AVLTree *a) {
    (*a) = (struct Node*) malloc (sizeof(struct Node));
    (*a)->Height = 0;
}
int isAVL(AVLTree a) {
    if(a == NULL) return 0;
    else if(a->Left == NULL || a->Right == NULL) return 1;
    else {
        int s = a->Left->Height - a->Right->Height;
        if(s >= -1 && s <= 1) return 1;
        else return 0;
    }
}
void printLRN(AVLTree a) {
    if(a != NULL) {
        printLRN(a->Left);
        printLRN(a->Right);
        printf("(%d - %d); ", a->Key, a->Height);
    }
}
AVLTree search(KeyType x, AVLTree a) {
    if(a != NULL) {
        if(a->Key == x) return a;
        else if(a->Key > x) return search(x, a->Left);
        else return search(x, a->Right);
    }
    return NULL;
}
int CountLeaves(AVLTree a) {
    if(a == NULL) return 0;
    if(a->Left == NULL && a->Right == NULL) return 1;
    return CountLeaves(a->Left) + CountLeaves(a->Right);
}
void printHeight(int x, AVLTree a) {
    if(a != NULL) {
        if(a->Height == x) printf("%d ", a->Key);
        printHeight(x, a->Left);
        printHeight(x, a->Right);
    }
}
int min(int a, int b) {
    if((a < b)) return a;
    else return b;
}
int getBalance(AVLTree a) {
    if(a == NULL) return 0;
    else return getBalance(a->Left) - getBalance(a->Right);
}
int getHeight2(AVLTree a) {
    if(a == NULL) {
        return -1;
    }
    else return a->Height;
}
void printNLR(AVLTree a) {
    if(a != NULL) {
        printf("(%d - %d); ", a->Key, a->Height);
        printNLR(a->Left);
        printNLR(a->Right);
    }
}