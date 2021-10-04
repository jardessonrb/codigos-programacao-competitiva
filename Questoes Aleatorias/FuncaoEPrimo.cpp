#include <stdio.h>
#include <stdlib.h>

bool eh_primo(int x){
	int resto;
	
	for(int i = 2; i < x; i++){
		resto = x % i;
		if(resto == 0){
			return false;
		}
	}
	return true;
}

int main(){

	int x;
	scanf("%d", &x);

	if(eh_primo(x)){
		printf("S");
	}else{
		printf("N");
	}

 	return 0;
}

