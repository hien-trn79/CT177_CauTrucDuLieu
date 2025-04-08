#include <stdio.h>
#include <malloc.h>

typedef int Data;
struct Node {
    Data Key;
    struct Node* Left;
    struct Node* Right;
};
typedef struct Node* Tree;
void makenullTree(Tree *a) {
    (*a) = NULL;
}
int isEmpty(Tree a) {
    if(a == NULL) return 1;
    else return 0;
}
Tree init() {
    Tree a = NULL;
    return a;
}
Tree leftChild(Tree a) {
    if(a != NULL) return a->Left;
    else return NULL;
}
Tree rightChild(Tree a) {
    if(a != NULL) return a->Right;
    else return NULL;
}
void insertNode(int x, Tree *a) {       // them node vao cay nhi phan
    if((*a) == NULL) {
        (*a) = (struct Node*) malloc (sizeof(struct Node));
        (*a)->Key = x;
        (*a)->Left = NULL;
        (*a)->Right = NULL;
    }
    else if(x > (*a)->Key) insertNode(x,&(*a)->Right);
    else insertNode(x, &(*a)->Left);
}
// cac dang duyet cay
void preOrder(Tree a) {
    if(a != NULL) {
        printf("%d ", a->Key);
        preOrder(a->Left);
        preOrder(a->Right);
    }
}
void inOrder(Tree a) {
    if(a != NULL) {
        inOrder(a->Left);
        printf("%d ", a->Key);
        inOrder(a->Right);
    }
}
void posOrder(Tree a) {
    if(a != NULL) {
        posOrder(a->Left);
        posOrder(a->Right);
        printf("%d ", a->Key);
    }
}
Tree rightSibling(int x, Tree a) {      // tra ve anh em ruot phai cua x
    Tree p = a;
    Tree temp = NULL;
    while(p != NULL) {
        if(p->Key == x) {
            if(temp != p) return temp;
            else return NULL;
        }
        temp = p->Right;
        if(p->Key > x) p = p->Left;
        else p = p->Right;
    }
    return NULL;
}
Tree getNext(int x, Tree a) {       // tra ve node sau x
    if(a != NULL) {
        if(a->Key == x) {
            if(a->Left != NULL) {
                Tree temp = a->Right;
                while(temp->Left != NULL) temp = temp->Left;
                return temp;
            }
        }
        if(a->Left != NULL) {
            Tree temp = a->Left;
            while(temp->Left != NULL) temp = temp->Right;
            if(temp->Key == x) return a;
        }
        if(a->Key < x) return getNext(x, a->Right);
        else return getNext(x, a->Left);
    }
    else return NULL;
}
Tree getPrevious(int x, Tree a) {   // tra ve node truoc x
    if(a != NULL) {
        if(a->Key == x && a->Left != NULL) {
            Tree temp = a->Left;
            while(temp->Right != NULL) temp = temp->Right;
            return temp;
        }
        Tree temp = a;
        if(a->Right != NULL) {
            a = a->Right;
            while(a->Left != NULL) a = a->Left;
            if(a->Key == x) return temp;
        }
        a = temp;
        if(x > a->Key) return getPrevious(x, a->Right);
        else return getPrevious(x, a->Left);
    }
    return NULL;
}
void printPath(int x, Tree a) {     // in duong di tim kiem du lieu
    if(a != NULL) {
        if(a->Key == x) {
            printf("%d -> Tim thay", a->Key);
        } else {
            printf("%d ", a->Key);
            if(a->Key > x) printPath(x, a->Left);
            else printPath(x, a->Right);
        }
    }
    if(a == NULL) printf("-> Khong tim thay");
}
Tree getParent(int x, Tree a) {     // tra ve node cha cua x
    if(a != NULL) {
        if(a->Key == x) return NULL;
        if(a->Left->Key == x || a->Right->Key == x) return a;
        if(x < a->Key) return getParent(x, a->Left);
        else return getParent(x, a->Right);
    }
    return NULL;
}
Tree search(int x, Tree a) {        // tim node x
    if(a != NULL) {
        if(a->Key == x) return a;
        if(x < a->Key) return a->Left;
        else return a->Right;
    }
    return NULL;
}
int getNb_Nodes(Tree a) {       // tong so node trong cay
    if(a == NULL) return 0;
    else return 1 + getNb_Nodes(a->Left) + getNb_Nodes(a->Right);
}
int getFullNodes(Tree a) {      // dem so node co 2 con
    if(a == NULL) return 0;
    else if(a->Left != NULL && a->Right != NULL) return 1+ getFullNodes(a->Left) + getFullNodes(a->Right);
    else {
        return getFullNodes(a->Left);
        return getFullNodes(a->Right);
    }
}
int max(int a, int b) {
    if(a > b) return a;
    else return b;
}
int getHeight(Tree a) {     // tinh chieu cua cay
    if(a == NULL) return -1;
    else return 1 + max(getHeight(a->Left), getHeight(a->Right));
}
int hNode(int x, Tree a) {      // tinh chieu cao cua 1 node
    if(a != NULL) {
        if(a->Key == x) return getHeight(a);
    }
    return NULL;
}
Tree minNodeRight(Tree a) {     // tim node nho nhat tren cay con phai
    if(a->Right != NULL) {
        Tree temp = a->Right;
        while(temp->Left != NULL) temp = temp->Left;
        return temp;
    }
    return NULL;
}
void deleteNode(int x, Tree *a) {   // xoa node 
    if(*a != NULL) {
        if((*a)->Key == x) {
            if((*a)->Left == NULL && (*a)->Right == NULL) (*a) = NULL;
            else {
                if((*a)->Left == NULL || (*a)->Right == NULL) {
                    if((*a)->Left != NULL) (*a) = (*a)->Left;
                    else (*a) = (*a)->Right;
                }
                else {
                    Tree temp = (*a)->Right;
                    while(temp->Left != NULL) temp = temp->Left;
                    deleteNode(temp->Key, &(*a));
                    (*a)->Key = temp->Key;
                }
            }
        }
        else if(x < (*a)->Key) deleteNode(x, &(*a)->Left);
        else deleteNode(x, &(*a)->Right);
    }
}
int member(int x, Tree a) {         // kiem tra x co trong cay hay khong
    Tree p = search(x, a);
    if(p == NULL) return 1;
    else return 0;
}
int isLeave(Tree a) {        // kiem tra nut la
    if(a->Left == NULL && a->Right == NULL) return 1;
    else return 0;
}

Tree readSetTree() {        // nhap cay khong trung
    Tree a = init();
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int t; scanf("%d", &t);
        if(member(t, a) == 0) insertNode(t, &a);
    }
    return a;
}