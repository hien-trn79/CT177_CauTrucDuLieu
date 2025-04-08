#include <stdio.h>
#include "pdathuc.c"

int main() {
    DaThuc d1=nhapDaThuc();		
	DaThuc d2=nhapDaThuc();		
	DaThuc d = congDaThuc(d1,d2);
	inDaThuc(d);
}