#include <stdio.h>
#include <stdlib.h>

struct Participante {
    int codigo;
    char nome[50];
    int situacao;
    int registrado;
};

struct Participante participantes[100];
int total = 0;

void cadastrar() {
    system("cls");
    printf("=== CADASTRAR PARTICIPANTE ===\n");

    if (total < 100) {
        printf("Digite o codigo: ");
        scanf("%d", &participantes[total].codigo);

        printf("Digite o nome: ");
        scanf(" %49[^\n]", participantes[total].nome);

        participantes[total].situacao = 1;
        participantes[total].registrado = 0;

        total++;
        printf("\nCadastro realizado com sucesso!\n");
    } else {
        printf("Limite de cadastros atingido!\n");
    }

    system("pause");
}

void listar() {
    int i;

    system("cls");
    printf("=== LISTAR PARTICIPANTES ===\n");

    if (total == 0) {
        printf("Nenhum participante cadastrado.\n");
    } else {
        for (i = 0; i < total; i++) {
            printf("-------------------------\n");
            printf("Codigo: %d\n", participantes[i].codigo);
            printf("Nome: %s\n", participantes[i].nome);
            printf("Situacao: %s\n",
                participantes[i].situacao == 1 ? "Ativo" : "Inativo");
            printf("Registrado: %s\n",
                participantes[i].registrado == 1 ? "Sim" : "Nao");
        }
    }

    system("pause");
}

void pesquisar() {
    int codigoBusca, i, achou = 0;

    system("cls");
    printf("=== PESQUISAR PARTICIPANTE ===\n");
    printf("Digite o codigo: ");
    scanf("%d", &codigoBusca);

    for (i = 0; i < total; i++) {
        if (participantes[i].codigo == codigoBusca) {
            printf("\nCodigo: %d\n", participantes[i].codigo);
            printf("Nome: %s\n", participantes[i].nome);
            printf("Situacao: %s\n",
                participantes[i].situacao == 1 ? "Ativo" : "Inativo");
            printf("Registrado: %s\n",
                participantes[i].registrado == 1 ? "Sim" : "Nao");

            achou = 1;
            break;
        }
    }

    if (achou == 0) {
        printf("\nParticipante nao encontrado.\n");
    }

    system("pause");
}

void atualizar() {
    int codigoBusca, i, achou = 0;
    int novaSituacao;

    system("cls");
    printf("=== ATUALIZAR SITUACAO ===\n");
    printf("Digite o codigo: ");
    scanf("%d", &codigoBusca);

    for (i = 0; i < total; i++) {
        if (participantes[i].codigo == codigoBusca) {
            printf("1 - Ativo\n");
            printf("2 - Inativo\n");
            printf("Escolha a situacao: ");
            scanf("%d", &novaSituacao);

            if (novaSituacao == 1) {
                participantes[i].situacao = 1;
                printf("\nSituacao atualizada!\n");
            } else if (novaSituacao == 2) {
                participantes[i].situacao = 0;
                printf("\nSituacao atualizada!\n");
            } else {
                printf("\nSituacao invalida!\n");
            }

            achou = 1;
            break;
        }
    }

    if (achou == 0) {
        printf("\nParticipante nao encontrado.\n");
    }

    system("pause");
}

void registrar() {
    int codigoBusca, i, achou = 0;

    system("cls");
    printf("=== REGISTRAR PARTICIPANTE ===\n");
    printf("Digite o codigo: ");
    scanf("%d", &codigoBusca);

    for (i = 0; i < total; i++) {
        if (participantes[i].codigo == codigoBusca) {

            if (participantes[i].situacao == 1) {
                participantes[i].registrado = 1;
                printf("\nRegistro realizado com sucesso!\n");
            } else {
                printf("\nParticipante inativo!\n");
            }

            achou = 1;
            break;
        }
    }

    if (achou == 0) {
        printf("\nParticipante nao encontrado.\n");
    }

    system("pause");
}

void resumo() {
    int i;
    int ativos = 0;
    int inativos = 0;
    int registrados = 0;

    system("cls");
    printf("=== RESUMO DO SISTEMA ===\n");

    for (i = 0; i < total; i++) {
        if (participantes[i].situacao == 1) {
            ativos++;
        } else {
            inativos++;
        }

        if (participantes[i].registrado == 1) {
            registrados++;
        }
    }

    printf("Total de participantes: %d\n", total);
    printf("Participantes ativos: %d\n", ativos);
    printf("Participantes inativos: %d\n", inativos);
    printf("Participantes registrados: %d\n", registrados);

    system("pause");
}

int main() {
    int opcao = 0;

    while (opcao != 7) {
        system("cls");

        printf("=== SISTEMA DE PARTICIPANTES ===\n");
        printf("01 - Cadastrar participante\n");
        printf("02 - Listar participantes\n");
        printf("03 - Pesquisar participante\n");
        printf("04 - Atualizar situacao\n");
        printf("05 - Registrar participante\n");
        printf("06 - Gerar resumo\n");
        printf("07 - Sair do sistema\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar();
                break;

            case 2:
                listar();
                break;

            case 3:
                pesquisar();
                break;

            case 4:
                atualizar();
                break;

            case 5:
                registrar();
                break;

            case 6:
                resumo();
                break;

            case 7:
                printf("\nSaindo do sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                system("pause");
                break;
        }
    }

    return 0;
}
