#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Acao {
    int codigo;
    char escola[60];
    char tema[60];
    int dia, mes, ano;
    char publico[40];
    char responsavel[50];
    int qtdPrevista;
    int qtdEfetiva;
    int situacao; 
};

struct Acao acoes[100];
int total = 0;

void lerLinha(char texto[], int tamanho) {
    int c;
    if (fgets(texto, tamanho, stdin) == NULL) {
        printf("\nEntrada encerrada.\n");
        exit(0);
    }
    if (strchr(texto, '\n') != NULL) {
        texto[strcspn(texto, "\n")] = '\0';
    } else {
        while ((c = getchar()) != '\n' && c != EOF) { }
    }
}

int lerInteiro(const char mensagem[]) {
    char texto[100], extra;
    int numero;
    while (1) {
        printf("%s", mensagem);
        lerLinha(texto, sizeof(texto));
        if (sscanf(texto, " %d %c", &numero, &extra) == 1) return numero;
        printf("Numero invalido! Tente novamente.\n");
    }
}

void lerObrigatorio(const char mensagem[], char destino[], int tamanho) {
    int i, preenchido;
    while (1) {
        printf("%s", mensagem);
        lerLinha(destino, tamanho);
        preenchido = 0;
        for (i = 0; destino[i] != '\0'; i++) {
            if (!isspace((unsigned char)destino[i])) preenchido = 1;
        }
        if (preenchido) return;
        printf("Erro: campo obrigatorio vazio.\n");
    }
}

int dataValida(int dia, int mes, int ano) {
    int diasMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (ano < 1 || mes < 1 || mes > 12) return 0;
    if (mes == 2 && ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)) diasMes[2] = 29;
    return dia >= 1 && dia <= diasMes[mes];
}

int buscarCodigo(int codigo) {
    int i;
    for (i = 0; i < total; i++) {
        if (acoes[i].codigo == codigo) return i;
    }
    return -1;
}

int contemTexto(char texto[], char busca[]) {
    int i, j;
    if (busca[0] == '\0') return 0;
    for (i = 0; texto[i] != '\0'; i++) {
        j = 0;
        while (busca[j] != '\0' && texto[i+j] != '\0' &&
               tolower((unsigned char)texto[i+j]) == tolower((unsigned char)busca[j])) j++;
        if (busca[j] == '\0') return 1;
    }
    return 0;
}

void mostrarAcao(int i) {
    printf("\n-------------------------\n");
    printf("Codigo: %d\n", acoes[i].codigo);
    printf("Escola: %s\n", acoes[i].escola);
    printf("Tema: %s\n", acoes[i].tema);
    printf("Data: %02d/%02d/%04d\n", acoes[i].dia, acoes[i].mes, acoes[i].ano);
    printf("Publico-alvo: %s\n", acoes[i].publico);
    printf("Responsavel: %s\n", acoes[i].responsavel);
    printf("Participantes previstos: %d\n", acoes[i].qtdPrevista);
    printf("Situacao: %s\n", acoes[i].situacao == 1 ? "Planejada" : acoes[i].situacao == 2 ? "Realizada" : "Cancelada");
    if (acoes[i].situacao == 2) printf("Participantes efetivos: %d\n", acoes[i].qtdEfetiva);
}

void cadastrar() {
    char data[80], extra;
    int codigo, dia, mes, ano, quantidade;
    system("cls");
    printf("=== CADASTRAR ACAO ===\n");
    if (total >= 100) {
        printf("Limite de armazenamento atingido!\n");
        system("pause");
        return;
    }
    while (1) {
        codigo = lerInteiro("Digite o codigo: ");
        if (codigo <= 0) printf("Codigo deve ser positivo!\n");
        else if (buscarCodigo(codigo) != -1) printf("Erro: codigo ja cadastrado.\n");
        else break;
    }
    acoes[total].codigo = codigo;
    lerObrigatorio("Digite a escola: ", acoes[total].escola, 60);
    lerObrigatorio("Digite o tema: ", acoes[total].tema, 60);
    while (1) {
        printf("Digite a data (dd/mm/aaaa): ");
        lerLinha(data, sizeof(data));
        if (sscanf(data, " %d/%d/%d %c", &dia, &mes, &ano, &extra) == 3 &&
            dataValida(dia, mes, ano)) break;
        printf("Erro: data invalida.\n");
    }
    acoes[total].dia = dia;
    acoes[total].mes = mes;
    acoes[total].ano = ano;
    lerObrigatorio("Digite o publico-alvo: ", acoes[total].publico, 40);
    lerObrigatorio("Digite o responsavel: ", acoes[total].responsavel, 50);
    while (1) {
        quantidade = lerInteiro("Quantidade prevista de participantes: ");
        if (quantidade > 0) break;
        printf("Erro: quantidade invalida (deve ser maior que zero).\n");
    }
    acoes[total].qtdPrevista = quantidade;
    acoes[total].qtdEfetiva = 0;
    acoes[total].situacao = 1;
    total++;
    printf("\nAcao cadastrada com sucesso! (%d/100)\n", total);
    system("pause");
}

void listar() {
    int i;
    system("cls");
    printf("=== LISTAR ACOES ===\n");
    if (total == 0) printf("Nenhuma acao cadastrada ate o momento.\n");
    for (i = 0; i < total; i++) mostrarAcao(i);
    system("pause");
}

void pesquisar() {
    int opcao, codigo, i, encontrados = 0;
    char busca[60];
    system("cls");
    printf("=== PESQUISAR ACAO ===\n");
    printf("1 - Por codigo\n2 - Por escola\n3 - Por tema\n");
    opcao = lerInteiro("Escolha: ");
    if (opcao == 1) {
        codigo = lerInteiro("Digite o codigo: ");
        i = buscarCodigo(codigo);
        if (i == -1) printf("Registro inexistente.\n");
        else mostrarAcao(i);
    } else if (opcao == 2 || opcao == 3) {
        lerObrigatorio("Digite o texto para pesquisar: ", busca, 60);
        for (i = 0; i < total; i++) {
            if ((opcao == 2 && contemTexto(acoes[i].escola, busca)) ||
                (opcao == 3 && contemTexto(acoes[i].tema, busca))) {
                mostrarAcao(i);
                encontrados++;
            }
        }
        if (encontrados == 0) printf("Nenhuma acao encontrada.\n");
        else printf("\n%d acao(oes) encontrada(s).\n", encontrados);
    } else printf("Opcao invalida!\n");
    system("pause");
}

void atualizar() {
    int codigo, i, situacao, quantidade;
    system("cls");
    printf("=== ATUALIZAR SITUACAO ===\n");
    codigo = lerInteiro("Digite o codigo da acao: ");
    i = buscarCodigo(codigo);
    if (i == -1) {
        printf("Registro inexistente.\n");
        system("pause");
        return;
    }
    printf("Situacao atual: %s\n", acoes[i].situacao == 1 ? "Planejada" : acoes[i].situacao == 2 ? "Realizada" : "Cancelada");
    printf("1 - Planejada\n2 - Realizada\n3 - Cancelada\n");
    situacao = lerInteiro("Nova situacao: ");
    if (situacao < 1 || situacao > 3) printf("Situacao invalida!\n");
    else {
        if (situacao == 2) {
            while (1) {
                quantidade = lerInteiro("Quantidade efetiva de participantes: ");
                if (quantidade >= 0) break;
                printf("Quantidade nao pode ser negativa!\n");
            }
            acoes[i].qtdEfetiva = quantidade;
        } else acoes[i].qtdEfetiva = 0;
        acoes[i].situacao = situacao;
        printf("Situacao atualizada com sucesso!\n");
    }
    system("pause");
}

void registrar() {
    int codigo, i, quantidade;
    system("cls");
    printf("=== REGISTRAR PARTICIPANTES ===\n");
    codigo = lerInteiro("Digite o codigo da acao: ");
    i = buscarCodigo(codigo);
    if (i == -1) printf("Registro inexistente.\n");
    else if (acoes[i].situacao != 2) printf("So e possivel registrar participantes de acoes realizadas.\n");
    else {
        printf("Previstos: %d | Registrados: %d\n", acoes[i].qtdPrevista, acoes[i].qtdEfetiva);
        while (1) {
            quantidade = lerInteiro("Nova quantidade efetiva: ");
            if (quantidade >= 0) break;
            printf("Quantidade nao pode ser negativa!\n");
        }
        acoes[i].qtdEfetiva = quantidade;
        printf("Participantes registrados com sucesso!\n");
    }
    system("pause");
}

void resumo() {
    int i, planejadas = 0, realizadas = 0, canceladas = 0;
    int previstos = 0, previstosRealizadas = 0, efetivos = 0;
    system("cls");
    printf("=== RESUMO GERAL ===\n");
    for (i = 0; i < total; i++) {
        previstos += acoes[i].qtdPrevista;
        if (acoes[i].situacao == 1) planejadas++;
        else if (acoes[i].situacao == 2) {
            realizadas++;
            efetivos += acoes[i].qtdEfetiva;
            previstosRealizadas += acoes[i].qtdPrevista;
        } else canceladas++;
    }
    printf("Total de acoes: %d\n", total);
    printf("Planejadas: %d\n", planejadas);
    printf("Realizadas: %d\n", realizadas);
    printf("Canceladas: %d\n", canceladas);
    printf("Participantes previstos (todas): %d\n", previstos);
    printf("Participantes efetivos: %d\n", efetivos);
    if (previstosRealizadas > 0)
        printf("Percentual de participacao: %.1f%%\n", 100.0 * efetivos / previstosRealizadas);
    else printf("Percentual de participacao: nao calculavel\n");
    system("pause");
}

int main() {
    int opcao = -1;
    while (opcao != 0) {
        system("cls");
        printf("=== PSE EM ACAO - PREVENCAO AO ALCOOL E DROGAS ===\n");
        printf("01 - Cadastrar acao\n");
        printf("02 - Listar acoes\n");
        printf("03 - Pesquisar acao\n");
        printf("04 - Atualizar situacao\n");
        printf("05 - Registrar participantes\n");
        printf("06 - Gerar resumo\n");
        printf("00 - Sair do sistema\n");
        opcao = lerInteiro("Digite uma opcao: ");
        switch (opcao) {
            case 1: cadastrar(); break;
            case 2: listar(); break;
            case 3: pesquisar(); break;
            case 4: atualizar(); break;
            case 5: registrar(); break;
            case 6: resumo(); break;
            case 0: printf("Saindo do sistema...\n"); break;
            default: printf("Opcao invalida!\n"); system("pause"); break;
        }
    }
    return 0;
}
