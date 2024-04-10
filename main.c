#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "main.h"
#include "funcoes.h"

#define CPF 11


int main() {

    #if defined(_WIN32) || defined(_WIN64)
        system("chcp 65001"); // troca para UTF-8
    #endif

    int escolha;
    do {
        printf("\nMenu:\n");
        printf("1. Inserir departamento\n");
        printf("2. Inserir funcionário\n");
        printf("3. Listar departamentos\n");
        printf("4. Listar funcionários\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch(escolha) {
            case 1:
                criarDepartamento();
                break;
            case 2:
                criarFuncionario();
                break;
            case 5:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while(escolha != 5);

    return 0;
}