#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool verificaVogal(char letra){
	
	if(letra == 'a' || letra == 'e' || letra == 'i'
	|| letra == 'o' || letra == 'u'){
		return true;
	}else{
		return false;
	}

}

bool verificaValidade(char risada[]){
	
	int contagem = 0;
	for(int i = 0; i < 50; i++){
		if(risada[i] == 'a' ||risada[i] == 'e' || risada[i] == 'i'
		|| risada[i] == 'o' || risada[i] == 'u'){
			contagem ++;
		}
	}
	
	if(contagem  < 1){
		return false;
	}
	return true;
	
}


int main(){
	
  char risada[50];
  char investida[50];
	int cont = 0;
  
  printf(": ");
  fflush(stdin);
  gets(risada);
  
  
  if(!verificaValidade(risada)){
		return 0;
	}

  for(int i = 50; i<0; i--){
			investida[cont] = risada[i];
			cont++;
  }
  printf("%s", investida);

	
  
  system("pause");
  
	return 0;
}

