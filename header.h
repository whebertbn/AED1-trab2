#include <stdlib.h>
#include <stdio.h>

// Declaração das structs Funcionario e Departamento
struct Funcionario;

typedef struct Departamento {
    int codigo;
    char nome[100];
    float percentualComissao;
    struct Funcionario* funcionarioLista;
} Departamento;

typedef struct Funcionario {
    char nome[100];
    char cpf[12];
    int idade;
    float salBruto;
    float salLiquido;
    int departamento; 
    struct Funcionario* next;
} Funcionario;

// Protótipo das funções


// Função que cria um departamento
Departamento* criarDepartamento(int codigo, char nome[100], float percentualComissao);

// Função que cria um funcionaário
Funcionario* criarFuncionario(char nome[100], char cpf[12], int idade, float salBruto, float salLiquido, int departamento);

// Função que cria uma lista de departamentos
Departamento* criarDepartamentoLista();

// Função que cria uma lista de funcionaários
Funcionario* criarFuncionarioLista();

