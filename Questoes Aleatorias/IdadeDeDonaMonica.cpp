#include <stdio.h>
#include <stdlib.h>

int main(){
	int M, A, B, C, V=0;
	scanf("%d%d%d", &M,&A,&B);
	V = A;
	if(M < 40 || M > 110 || A < 1 || A > M || B < 1 || B > M || A == B){
		return 0;
	}
	C = M - (A + B);
	
	(V < B)? V=B : V;
	(V <= C)? V=C: V;
	
	
	
	printf("%d",V);

	return 0;
}

