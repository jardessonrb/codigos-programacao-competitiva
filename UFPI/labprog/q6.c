/*
Aluno - Járdesson Ribeiro
Curso - Ciência da computação UFPI
Disciplina - Laboratorio de programação
Resumo questão - Dado uma senha, verificar se é igual a que já está definida.
*/
#include <stdio.h>
#include <string.h>


int main(){
    char senhaSistema[9] = {'k', 'l', '2', '3', 'f', '5', 'g', '0', '\0'};
    char senhaInserida[30];
    //kl23f5g0
    int resultado;

    while(true){
        printf("Digite a senha: ");
        gets(senhaInserida);
        
        resultado = strcmp(senhaSistema, senhaInserida);
        printf("%s \n", senhaSistema);

        if(resultado == 0){
            printf("Senha valida ...\n");
            break;
        }else{
            printf("Senha invalida ...\n");
        }
    }

    return 0;
}