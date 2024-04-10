#define CPF 11

typedef struct Departamento {
    int codigo;
    char nome[50];
    float percentual_bonus;
    struct Departamento *proximo;
} Departamento;

typedef struct Funcionario {
    char nome[50];
    char cpf[CPF + 1];
    int idade;
    float salario_bruto;
    Departamento *departamento;
    struct Funcionario *anterior;
    struct Funcionario *proximo;
} Funcionario;

// Variáveis globais
Departamento *cabeca_departamento = NULL;
Funcionario *cabeca_funcionario = NULL;

// Protótipos de função
void criarDepartamento();
void criarFuncionario();
void validarCPF(const char *cpf);
