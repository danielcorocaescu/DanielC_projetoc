#ifndef VV_H_INCLUDED
#define VV_H_INCLUDED
#include <conio.c>

#define MAX_DESCRICAO 50
#define MAX_CATEGORIA 20
#define MAX_REGISTROS 100

typedef struct {
    char descricao[MAX_DESCRICAO];
    char categoria[MAX_CATEGORIA];
    float valor;
} Despesa;

void cadastrarDespesa(Despesa* despesas, int* numDespesas) {
    if (*numDespesas >= MAX_REGISTROS) {
        printf("Limite de despesas atingido.\n");
        return;
    }

    Despesa novaDespesa;

    textcolor(LIGHTBLUE);

    printf("Digite a descrição da despesa: ");
    fgets(novaDespesa.descricao, MAX_DESCRICAO, stdin);
    novaDespesa.descricao[strcspn(novaDespesa.descricao, "\n")] = '\0';

    printf("Digite a categoria da despesa: ");
    fgets(novaDespesa.categoria, MAX_CATEGORIA, stdin);
    novaDespesa.categoria[strcspn(novaDespesa.categoria, "\n")] = '\0';

    printf("Digite o valor da despesa: ");
    scanf("%f", &novaDespesa.valor);
    getchar();

    despesas[*numDespesas] = novaDespesa;
    (*numDespesas)++;

    textcolor(LIGHTGREEN);

    printf("\n");

    printf("Despesa registrada com sucesso!\n");
}

void exibirDespesas(Despesa* despesas, int numDespesas) {
    if (numDespesas == 0) {
        printf("Nenhuma despesa registrada.\n");
        return;
    }
    else{
    textcolor(GREEN);
    printf("Lista de despesas:\n");
    printf("\n");
    for (int i = 0; i < numDespesas; i++) {
        textcolor(YELLOW);
        printf("Descrição: %s\n", despesas[i].descricao);
        printf("Categoria: %s\n", despesas[i].categoria);
        printf("Valor: %.2f\n", despesas[i].valor);
        printf("----------------------------\n");
    }
    }
}

void salvarDespesas(Despesa* despesas, int numDespesas) {
    FILE* ficheiro = fopen("despesas.txt", "w");
    if (ficheiro == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    for (int i = 0; i < numDespesas; i++) {
        fprintf(ficheiro, "%s;%s;%.2f\n", despesas[i].descricao, despesas[i].categoria, despesas[i].valor);
    }

    fclose(ficheiro);

    textcolor(LIGHTGREEN);

    printf("Despesas salvas com sucesso!\n");
}

void carregarDespesas(Despesa* despesas, int* numDespesas) {
    FILE* ficheiro = fopen("despesas.txt", "r");
    if (ficheiro == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    *numDespesas = 0;
    char linha[MAX_DESCRICAO + MAX_CATEGORIA + 8];

    while (fgets(linha, sizeof(linha), ficheiro)) {
        Despesa novaDespesa;
        sscanf(linha, "%[^;];%[^;];%f", novaDespesa.descricao, novaDespesa.categoria, &novaDespesa.valor);
        despesas[*numDespesas] = novaDespesa;
        (*numDespesas)++;
    }

    fclose(ficheiro);
    printf("Despesas carregadas com sucesso!\n");
}

void modificarDespesa(Despesa* despesas, int numDespesas) {
    if (numDespesas == 0) {
        printf("Nenhuma despesa cadastrada.\n");
        return;
    }
    else
    {
    textcolor(GREEN);
    printf("Lista de despesas:\n");
    printf("\n");

    for (int i = 0; i < numDespesas; i++) {
        textcolor(YELLOW);
        printf("Número: %d\n", i); // Número de identificação
        printf("Descrição: %s\n", despesas[i].descricao);
        printf("Categoria: %s\n", despesas[i].categoria);
        printf("Valor: %.2f\n", despesas[i].valor);
        printf("----------------------------\n");
    }
    }

    int indice;

    textcolor(YELLOW);
    printf("Digite o índice da despesa que deseja modificar (0 a %d): ", numDespesas - 1);
    scanf("%d", &indice);
    getchar();

    if (indice < 0 || indice >= numDespesas) {
        printf("Índice inválido.\n");
        return;
    }

    Despesa despesaModificada;

    printf("Digite a nova descrição da despesa: ");
    fgets(despesaModificada.descricao, MAX_DESCRICAO, stdin);
    despesaModificada.descricao[strcspn(despesaModificada.descricao, "\n")] = '\0';

    printf("Digite a nova categoria da despesa: ");
    fgets(despesaModificada.categoria, MAX_CATEGORIA, stdin);
    despesaModificada.categoria[strcspn(despesaModificada.categoria, "\n")] = '\0';

    printf("Digite o novo valor da despesa: ");
    scanf("%f", &despesaModificada.valor);
    getchar();

    despesas[indice] = despesaModificada;

    textcolor(LIGHTGREEN);
    printf("Despesa modificada com sucesso!\n");
}


#endif // VV_H_INCLUDED
