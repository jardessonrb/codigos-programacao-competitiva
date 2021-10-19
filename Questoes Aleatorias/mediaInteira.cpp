#include <stdio.h>
#include <stdlib.h>

int main(){
	int A, B, media;
	
	scanf("%d", &A);
	scanf("%d", &B);
	if(A > 1000 || B > 1000){
		return 0;
	}
	
	media = (A + B) / 2;
	
	printf("%d", media);
	return 0;
}

