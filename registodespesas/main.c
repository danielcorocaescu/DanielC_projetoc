#include <stdio.h>
#include <stdlib.h>
#include "vv.h"
#include "locale.h"




int main() {
    setlocale(LC_ALL,"Portuguese");
    Despesa despesas[MAX_REGISTROS];
    int numDespesas = 0;
    int opcao;

    carregarDespesas(despesas, &numDespesas);

    printf("\n");

    textcolor(RED);

    printf(R"EOF(  _____            _     _              _        _____
|  __ \          (_)   | |            | |      |  __ \
| |__) |___  __ _ _ ___| |_ ___     __| | ___  | |  | | ___  ___ _ __   ___  ___  __ _ ___
|  _  // _ \/ _` | / __| __/ _ \   / _` |/ _ \ | |  | |/ _ \/ __| '_ \ / _ \/ __|/ _` / __|
| | \ \  __/ (_| | \__ \ || (_) | | (_| |  __/ | |__| |  __/\__ \ |_) |  __/\__ \ (_| \__ \
|_|  \_\___|\__, |_|___/\__\___/   \__,_|\___| |_____/ \___||___/ .__/ \___||___/\__,_|___/
             __/ |                                              | |
            |___/                                               |_|

 )EOF");

    do {
        textcolor(MAGENTA);
        printf("=== Gerenciador de Despesas ===\n");
        printf("1. Registar despesa\n");
        printf("2. Mostrar despesas\n");
        printf("3. Guardar despesas\n");
        printf("4. Limpar consola\n");
        printf("5. Alterar despesas\n");
        printf("6. Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);
        getchar();
        printf("\n");

        switch (opcao) {
            case 1:
                cadastrarDespesa(despesas, &numDespesas);
                break;
            case 2:
                exibirDespesas(despesas, numDespesas);
                break;
            case 3:
                salvarDespesas(despesas, numDespesas);
                break;

            case 4:
                system("cls");
                break;

            case 5:
                modificarDespesa(despesas, numDespesas);
                break;

            case 6:
                textcolor(RED);
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida.\n");
        }

        printf("\n");


    } while (opcao != 6);

    return 0;
}
