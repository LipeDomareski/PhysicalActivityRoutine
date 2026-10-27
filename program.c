#include <stdio.h>
#include <string.h>

int main() {

    char *dias[7] = {"Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado", "Domingo"};
    int minutos[7] = {0};
    char exercicios[7][50];

    for (int i = 0; i < 7; i++) {
        strcpy(exercicios[i], "Nenhum");
    }

    int opcao;

    do {
        printf("\n=== ROTINA DE ATIVIDADES ===\n");
        printf("1. Registrar exercício\n");
        printf("2. Consultar semana\n");
        printf("3. Ver o 'Top Day'\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int dia;
            printf("\nEscolha o dia (1-Segunda a 7-Domingo): ");
            scanf("%d", &dia);

            if (dia >= 1 && dia <= 7) {
                int indice = dia - 1;
                
                getchar();

                printf("Qual exercício você fez? ");
                fgets(exercicios[indice], 50, stdin);
                exercicios[indice][strcspn(exercicios[indice], "\n")] = 0;

                printf("Quantos minutos durou? ");
                scanf("%d", &minutos[indice]);

                printf("Registrado com sucesso!\n");
            } else {
                printf("Dia inválido!\n");
            }

        } else if (opcao == 2) {
            printf("\n--- SUA ROTINA DA SEMANA ---\n");
            for (int i = 0; i < 7; i++) {
                printf("%s: %s (%d min)\n", dias[i], exercicios[i], minutos[i]);
            }

        } else if (opcao == 3) {
            int diaMaisAtivo = 0;
            for (int i = 1; i < 7; i++) {
                if (minutos[i] > minutos[diaMaisAtivo]) {
                    diaMaisAtivo = i;
                }
            }

            printf("\n TOP DAY DA SEMANA \n");
            if (minutos[diaMaisAtivo] == 0) {
                printf("Nenhuma atividade registrada ainda.\n");
            } else {
                printf("O dia mais ativo foi **%s** com %d minutos! (%s)\n", 
                    dias[diaMaisAtivo], minutos[diaMaisAtivo], exercicios[diaMaisAtivo]);
            }
        }

    } while (opcao != 0);

    printf("Programa encerrado.\n");
    return 0;
}