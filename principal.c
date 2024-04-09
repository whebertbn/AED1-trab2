#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"


Departamento* criarDepartamentoLista(){
    Departamento* departamento = (Departamento*) malloc(sizeof(Departamento));
    return departamento;
}

Funcionario* criarFuncionarioLista(){
    Funcionario* funcionario = (Funcionario*) malloc(sizeof(Funcionario));
    return funcionario;
}

Departamento* criarDepartamento(int codigo, char nome[100], float percentualComissao){

    Departamento* novoDepartamento = (Departamento*)malloc(sizeof(Departamento));
    novoDepartamento->codigo = codigo;
    strcpy(novoDepartamento->nome, nome);
    novoDepartamento->percentualComissao = percentualComissao;
    novoDepartamento->funcionarioLista = NULL;
    return novoDepartamento;

}





int main(void)
{

#if defined(_WIN32) || defined(_WIN64)
    system("chcp 65001"); // troca para UTF-8
#endif

    int escolha;
    Departamento departamentos[25];
    Funcionario funcionarios[25];

    do
    {
        printf("\nEscolha a operacao:\n");
        printf("1. \n");
        printf("2. \n");
        printf("3. \n");
        printf("4. \n");
        printf("5. \n");
        printf("0. Sair\n");
        printf("Digite o numero da operacao desejada: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 0:
            printf("Saindo do programa. Obrigado!\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}
