/*
Aluno - Járdesson Ribeiro
Curso - Ciência da computação UFPI
Disciplina - Laboratorio de programação
Resumo questão - Verificar se uma palavra faz parte de uma frase.
*/
#include <stdio.h>
#include <string.h>

int main(){
    char frase[100], nome[30];
    int i, lengthNome, initNomeFrase = 0, flagInterna = 1, flagExterna = 0;
    printf("Digite a frase: ");
    gets(frase);
    printf("Digite a palavra: ");
    gets(nome);
	lengthNome = strlen(nome);
    for(i = 0; i < strlen(frase) + 1; i++){
        if(frase[i] == ' ' || frase[i] == '\0'){
        	int h = 0;
			while(h < lengthNome){
				if(nome[h] != frase[initNomeFrase]){
					flagInterna = 0;
				}
				initNomeFrase++;
				h++;
			}
			initNomeFrase = i + 1;
			if(flagInterna == 1){
				flagExterna = 1;
				break;
			}
			
			flagInterna = 1;
		}
    }  
	
	printf((flagExterna == 0) ? "NAO SUBSTRING" : "SUBSTRING");

    return 0;
}