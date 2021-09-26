/*
Aluno - Járdesson Ribeiro
Curso - Ciência da computação UFPI
Disciplina - Laboratorio de programação
Resumo questão - Dado uma frase, imprimir metade dela sem vogais	
*/
#include <stdio.h>
#include <string.h>

int ehVogal(char letra){
    int i;
    char vogais [] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (i = 0; i < 10; i++)
    {
       if(vogais[i] == letra){
           return 1;
       }
    }

    return 0;    
}

int main(){
    char frase[100];
    int i, length;

    printf("Digite a frase: ");
    gets(frase);
    length = (strlen(frase) / 2);
    
    for (i = 0; i < strlen(frase); i++)
    {
        if(i <= length){
            if(!ehVogal(frase[i])){
                printf("%c", frase[i]);
            }
        }
        else{
            printf("%c", frase[i]);
        }
    }
   

    return 0;
}