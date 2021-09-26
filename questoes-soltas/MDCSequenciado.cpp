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
	int N, maior = 0, dv=2, resto;
	bool pause = false;
	
	scanf("%d",&N);
	if(N < 2){return 0;}
	int M[N];
	for(int i = 0; i < N; i++){
		scanf("%d", &M[i]);
	}
	
	while(pause == false){
		int cont = 0;
		for(int t = 0; t < N; t++){
	    resto = M[t]%dv;
	    if(resto == 1){
				cont++;
      }
	    if(cont == N){
	    	maior = dv;
	    	pause = true;
			}
	    
		}
		
		dv++;
	}
	
	printf("%d", maior);
	

	return 0;
}

