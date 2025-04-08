#include <stdio.h>
#include <malloc.h>

typedef int ElementType;
struct Node {
    ElementType Element;
    struct Node* Next;
};
typedef struct Node Node;
typedef Node* Position;
typedef Position List;

void makenullList(List *a) {
    (*a) = (struct Node*) malloc (sizeof(struct Node));
    (*a)->Next = NULL;
}
Position endList(List a) {
    Position p = a;
    while(p->Next != NULL) {
        p = p->Next;
    }
    return p;
}
void append(ElementType x, List *a) {       // chen phan tu x vao cuoi danh sach
    Position p = endList(*a);
    Position t = (struct Node*) malloc (sizeof(struct Node));
    t->Element = x;
    t->Next = p->Next;
    p->Next = t;
} 
void printList(List a) {
    for(Position p = a; p->Next != NULL; p=p->Next) {
        printf("%d ", p->Next->Element);
    }
    printf("\n");
}
List nhap() {
    List a;
    makenullList(&a);
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int t; scanf("%d", &t);
        append(t, &a);
    }
    return a;
}
void deleteList(Position p, List *a) {
    Position t = (struct Node*) malloc (sizeof(struct Node));
    t = p->Next;
    p->Next = t->Next;
    free(t);
}
void deleteFirst(int x, List* a) {
    Position p = *a;
    while(p->Next != NULL) {
        if(p->Next->Element == x) {
			deleteList(p, a);
    		break;
		}
		else p = p->Next;
    }
    printList(*a);
}
int main() {
    List a = nhap();
    int x; scanf("%d", &x);
    printList(a);
    deleteFirst(x, &a);
}