#include <stdio.h>
#include "pdathuc.c"

int main() {
 DaThuc d = khoitao();
	struct Node *p=d;
	DonThuc s1 = {6.2, 4};
	DonThuc s2 = {4.2, 0};
	DonThuc s3 = {2, 4};
	chenDonThuc2(s1, &d);
	chenDonThuc2(s2, &d);
	chenDonThuc2(s3, &d);
	
	while(p->Next!=NULL)
	{
		DonThuc e = p->Next->e;
		printf("%.3fX^%d ",e.he_so,e.bac);
		p=p->Next;
	}
}