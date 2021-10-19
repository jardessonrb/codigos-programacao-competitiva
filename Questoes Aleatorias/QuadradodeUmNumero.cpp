#include <stdio.h>
#include <stdlib.h>

int main(){
  int L, Q;
  scanf("%d", &L);
  if(L < 1 || L > 1000){
		return 0;
	}else{
		Q = L * L;
	  printf("%d", Q);
	}
	return 0;
}

