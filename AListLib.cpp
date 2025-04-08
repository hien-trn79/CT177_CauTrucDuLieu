#include <stdio.h>

#define max 100
typedef int Element;
typedef int Position;
typedef struct {
    Element Elements[100];
    Position Last;
} List;

void makenullList(List *a) {
    a->Last = 0;
}
void insertList(int x, Position p, List *a) {
    if(a->Last == max) printf("Ds day!");
    else if(p < 1 && p > a->Last + 1) printf("Vi tri khong hop le\n");
    else {
        for(int i=a->Last; i>=p; i--) {
            a->Elements[i] = a->Elements[i-1];
        }
        a->Elements[p-1] = x;
        a->Last++;
    }
}
void deleteList(Position p, List *a) {
    if(p < 1 || p > a->Last) printf("Vi tri khong hop le\n");
    else {
        printf("%d\n", a->Last);
        for(int i=p; i<a->Last+1; i++) {
            a->Elements[i-1] = a->Elements[i];
        }
        a->Last--;
    }
}