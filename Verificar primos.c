// Essa é uma implementação em linguagem C do "Crivo de Eratóstenes", o algoritmo mais eficiente
//  do mundo para verificar quais são os números primos (divisíveis apenas por 1 e por ele mesmo)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 10000000 // Defina um limite máximo para o array de primos

int primos[MAX];
int comparacoes;
double tempo_raiz;

void resultados(double tempo) {
    printf("Tempo: %.2f segundos\n", tempo);
    printf("Comparacoes: %d\n", comparacoes);
    printf("Quantidade de primos: %d\n", primos[0]);
    // Descomente as linhas abaixo se quiser imprimir na tela os números primos
    // printf("Primos: ");
    // for (int i = 1; i <= primos[0]; i++) {
    //     printf("%d ", primos[i]);
    // }
    // printf("\n\n");
}

void metodo_raiz(int numero) {
    comparacoes = 0;
    primos[0] = 0; // Inicializa o contador de primos
    primos[++primos[0]] = 2; // Adiciona o número 2 como primo
    primos[++primos[0]] = 3; // Adiciona o número 3 como primo

    clock_t inicio = clock();
    for (int i = 5; i <= numero; i += 2) {
        int eh_primo = 1;
        for (int j = 2; j <= primos[0]; j++) {
            if (primos[j] > sqrt(i)) break;
            comparacoes++;
            if (i % primos[j] == 0) {
                eh_primo = 0;
                break;
            }
        }
        if (eh_primo) {
            primos[++primos[0]] = i;
        }
    }
    clock_t fim = clock();
    printf("Metodo Eratostenes\n");
    tempo_raiz = (double)(fim - inicio) / CLOCKS_PER_SEC;
    resultados(tempo_raiz);
}

int main() {
    int numero;
    printf("Digite ate que numero deseja verificar se eh primo: ");
    scanf("%d", &numero);

    metodo_raiz(numero);

    printf("\nAperte ENTER para sair...");
    getchar();
    getchar();

    return 0;
}