#include <stdio.h>
#include <stdlib.h>


int buscabi(int *vet, int chave, int inicio, int fim) {
    int meio;
    if (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (chave == vet[meio]) {
            return meio; 
        } else {
            if (chave < vet[meio]) {
                return buscabi(vet, chave, inicio, meio - 1);
            } else {
                return buscabi(vet, chave, meio + 1, fim);
            }
        }
    }
    return -1;
}


void inserirElemento(int *vet, int *tam, int elemento) {
    int i, j;
  
    for (i = 0; i < *tam && vet[i] < elemento; i++);

    for (j = *tam; j > i; j--) {
        vet[j] = vet[j - 1];
    }
    vet[i] = elemento;
    (*tam)++;
}


void removerElemento(int *vet, int *tam, int elemento) {
    int i, j;
    
    for (i = 0; i < *tam && vet[i] != elemento; i++);
  
    if (i < *tam) {
      
        for (j = i; j < *tam - 1; j++) {
            vet[j] = vet[j + 1];
        }
        (*tam)--;
    }
}

int main() {
    int vet[6] = {1, 3, 4, 5, 12, 19}; 
    int tam = 6; 
    int valor, op, elemento;

    do {
        printf("\nDigite um valor para busca: ");
        scanf("%d", &valor);
        int resultado = buscabi(vet, valor, 0, tam - 1);
        if (resultado != -1) {
            printf("Resultado: Elemento encontrado na posicao %d\n", resultado);
        } else {
            printf("Resultado: Elemento nao encontrado\n");
        }

        printf("\n0 - Sair\n1 - Remover Elemento\n2 - Inserir Elemento\nEscolha a opcao: ");
        scanf("%d", &op);

        if (op == 1) {
            printf("\nDigite o elemento a ser removido: ");
            scanf("%d", &elemento);
            removerElemento(vet, &tam, elemento);
            printf("Elemento removido.\n");
        } else if (op == 2) {
            printf("\nDigite o elemento a ser inserido: ");
            scanf("%d", &elemento);
            inserirElemento(vet, &tam, elemento);
            printf("Elemento inserido.\n");
        } else if (op != 0) {
            printf("\nOpcao invalida. Tente novamente.\n");
        }

    } while (op != 0);

    return 0;
}
