#include <stdio.h>
#include <math.h>
#include <malloc.h>

typedef struct {        // don thuc co dang 1|2 => x mu 2
    double he_so;
    int bac;
} DonThuc;
struct Node {
    DonThuc e;
    struct Node* Next;
};
typedef struct Node* Position;
typedef Position DaThuc;

Position cuoiDaThuc(DaThuc a) {
    Position p = a;
    while(p->Next != NULL) {
        p = p->Next;
    }
    return p;
}
DaThuc khoitao() {
    DaThuc a = (struct Node*) malloc (sizeof(struct Node));
    a->Next = NULL;
    return a;
}
void chenDonThuc(DonThuc e, DaThuc *a) {
    Position p = cuoiDaThuc(*a);
    DaThuc t = (struct Node*) malloc (sizeof(struct Node));
    t->Next = p->Next;
    t->e = e;
    p->Next = t;
}
void chenDonThuc2(DonThuc e, DaThuc *a) {       // chen da thuc theo thu tu
    Position p = *a;
    int found = 0; 
    Position t = (struct Node*) malloc (sizeof(struct Node));
    while(p->Next != NULL && found == 0) {
        if(p->Next->e.bac == e.bac) {
            p->Next->e.he_so += e.he_so;
            found++;
        } else if(p->Next->e.bac < e.bac) {
            t->Next = p->Next;
            t->e = e;
            p->Next = t;
            found++;
        }
        p = p->Next;
    }
    if(found == 0) {
        t->Next = p->Next;
        t->e = e;
        p->Next = t;
    }
}
DaThuc nhapDaThuc() {
    DaThuc a = khoitao();
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int he_so, bac;
        scanf("%d%d", &he_so, &bac);
        DonThuc temp = {he_so, bac};
        chenDonThuc2(temp, &a);
    }
    return a;
}
DaThuc congDaThuc(DaThuc a, DaThuc b) {
    DaThuc c = khoitao();
    Position p = a;
    Position q = b;
    while(p->Next != NULL) {
        chenDonThuc2(p->Next->e, &c);
        p = p->Next;
    }
    while(q->Next != NULL) {
        chenDonThuc2(q->Next->e, &c);
        q = q->Next;
    }
    return c;
}
void deleteDonThuc(Position p, DaThuc *a) {
    Position t = (struct Node*) malloc (sizeof(struct Node));
    t = p->Next;
    p->Next = t->Next;
    free(t);
}
void chuanhoa(DaThuc *d) {
    Position p = *d;
    int cnt;
    while(p->Next != NULL) {
        cnt = 0;
        Position q = p->Next;
        while(q->Next != NULL) {
            if(p->Next->e.bac == q->Next->e.bac) {
                p->Next->e.he_so += q->Next->e.he_so;
                deleteDonThuc(q, d);
            }
            q = q->Next;
        }
        p = p->Next;
    }
}
void sortDaThuc(DaThuc *d) {    // sap xep cac da thuc theo so mu giam dan
    Position p = *d;
    while(p->Next != NULL) {
        Position q= p->Next;
        while(q->Next != NULL) {
            if(p->Next->e.bac < q->Next->e.bac) {
                DonThuc x = p->Next->e;
                p->Next->e = q->Next->e;
                q->Next->e = x;
            }
            q = q->Next;
        }
        p = p->Next;
    }
}
void inDaThuc(DaThuc d) {
    Position k = d;
//    sortDaThuc(&d);
 //   chuanhoa(&d);
    while(k->Next != NULL) {
        printf("%.3lfX^%d", k->Next->e.he_so, k->Next->e.bac);
        if(k->Next->Next != NULL) printf(" + ");
        k = k->Next;
    }
}
DaThuc tinhDaoHam(DaThuc d) {
    DaThuc t = d;
    while(d->Next != NULL) {
        t->Next->e.he_so = d->Next->e.he_so * d->Next->e.bac;
        t->Next->e.bac = d->Next->e.bac -1;
        d = d->Next;
    }
    return t;
}