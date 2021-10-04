/*
Aluno - Járdesson Ribeiro
Curso - Ciência da computação UFPI
Disciplina - Laboratorio de programação
Resumo questão - Por que usar strcpy() e não o operador = (igual).
*/
#include <stdio.h>
#include <string.h>


int main(){
    char val1[30], val2[30];

    printf("Digite o nome: ");
    gets(val1);
    
    strcpy(val2, val1);
    /*A função strcpy recebe o valor de uma varial, sendo string em c
    e atribui a outra variavel. Em C, quando trata-se de um array de char
    uma string, o sinal de atribuição = (igual) não funciona, por isso é usada
    essa função da biblioteca string.h
    */

    printf("%s", val2);

    return 0;
}