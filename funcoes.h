#include <stdio.h>
#include <stdlib.h>

#define CPF 11
                                                            
void criarDepartamento() {
    // criando um novo departamento
    Departamento *novo_departamento = (Departamento *)malloc(sizeof(Departamento));
    // verificando se a alocação foi bem sucedida
    if(novo_departamento == NULL) {
        printf("Erro: memória insuficiente.\n");
        return;
    }

    printf("\nInserir Departamento:\n");
    printf("Código: ");
    scanf("%d", &novo_departamento->codigo);

    // Verifica se o departamento já existe
    Departamento *temp = cabeca_departamento;
    while(temp != NULL) {
        if(temp->codigo == novo_departamento->codigo) {
            printf("Erro: departamento com código %d já existe.\n", novo_departamento->codigo);
            free(novo_departamento);
            return;
        }
        temp = temp->proximo;
    }

    printf("Nome: ");
    scanf("%s", novo_departamento->nome);
    printf("Percentual de bonificação: ");
    scanf("%f", &novo_departamento->percentual_bonus);

    novo_departamento->proximo = NULL;

    // Inserindo o novo departamento na lista encadeada
    if(cabeca_departamento == NULL || novo_departamento->codigo < cabeca_departamento->codigo) {
        novo_departamento->proximo = cabeca_departamento;
        cabeca_departamento = novo_departamento;
    } else {
        temp = cabeca_departamento;
        while(temp->proximo != NULL && temp->proximo->codigo < novo_departamento->codigo) {
            temp = temp->proximo;
        }
        novo_departamento->proximo = temp->proximo;
        temp->proximo = novo_departamento;
    }

    printf("Departamento inserido com sucesso.\n");
}

void criarFuncionario() {
    // criando um novo funcionário
    Funcionario *novo_funcionario = (Funcionario *)malloc(sizeof(Funcionario));
    // verificando se a alocação foi bem sucedida
    if(novo_funcionario == NULL) {
        printf("Erro: memória insuficiente.\n");
        return;
    }

    printf("\nInserir Funcionário:\n");
    printf("Nome: ");
    scanf("%s", novo_funcionario->nome);

    printf("CPF (apenas números): ");
    scanf("%s", novo_funcionario->cpf);
    // verifica se o cpf tem 11 dígitos
    if(strlen(novo_funcionario->cpf) != CPF) {
        printf("Erro: CPF deve conter %d dígitos.\n", CPF);
        free(novo_funcionario);
        return;
    }

    validarCPF(novo_funcionario->cpf);

    printf("Idade: ");
    scanf("%d", &novo_funcionario->idade);
    printf("Salário Bruto: ");
    scanf("%f", &novo_funcionario->salario_bruto);

    printf("Departamento (código): ");
    int codigo_departamento;
    scanf("%d", &codigo_departamento);

    // encontrando o departamento correspondente
    Departamento *dept_temp = cabeca_departamento;
    while(dept_temp != NULL) {
        if(dept_temp->codigo == codigo_departamento) {
            novo_funcionario->departamento = dept_temp;
            break;
        }
        dept_temp = dept_temp->proximo;
    }
    // verificar se o departamento existe
    if(dept_temp == NULL) {
        printf("Erro: Departamento com código %d não encontrado.\n", codigo_departamento);
        free(novo_funcionario);
        return;
    }

    // Inserindo o novo funcionário na lista encadeada
    if(cabeca_funcionario == NULL) {
        // Lista vazia, inserir o nó cabeça primeiro
        cabeca_funcionario = (Funcionario *)malloc(sizeof(Funcionario));
        cabeca_funcionario->proximo = novo_funcionario;
        novo_funcionario->anterior = cabeca_funcionario;
        novo_funcionario->proximo = NULL;
    } else {
        // Inserindo no final da lista
        Funcionario *temp = cabeca_funcionario;
        while(temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novo_funcionario;
        novo_funcionario->anterior = temp;
        novo_funcionario->proximo = NULL;
    }

    printf("Funcionário inserido com sucesso.\n");
}

void validarCPF(const char *cpf) {
    int i, j;
    int soma, digito;
    char temp[CPF];

    // Copia o CPF para uma string temporária
    strcpy(temp, cpf);

    // Verifica se todos os dígitos são iguais
    for(i = 1; i < CPF; i++) {
        if(temp[i] != temp[0]) {
            break;
        }
    }
    if(i == CPF) {
        printf("Erro: CPF inválido.\n");
        exit(1);
    }

    // Calcula o primeiro dígito verificador
    soma = 0;
    for(i = 0; i < 9; i++) {
        soma += (temp[i] - '0') * (10 - i);
    }
    digito = 11 - (soma % 11);
    if(digito >= 10) {
        digito = 0;
    }
    if(digito != temp[9] - '0') {
        printf("Erro: CPF inválido.\n");
        exit(1);
    }

    // Calcula o segundo dígito verificador
    soma = 0;
    for(i = 0; i < 10; i++) {
        soma += (temp[i] - '0') * (11 - i);
    }
    digito = 11 - (soma % 11);
    if(digito >= 10) {
        digito = 0;
    }
    if(digito != temp[10] - '0') {
        printf("Erro: CPF inválido.\n");
        exit(1);
    }
}