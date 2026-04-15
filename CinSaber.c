#include <stdlib.h>
#include <stdio.h>

// Média
float calcularMedia(float *valores, int y) {
    if (y == 0) return 0;
    float sum = 0;
    for (int i = 0; i < y; i++) sum += valores[i];
    return sum / y;
}

// Maior Nota
int localizarMaior(float *valores, int y) {
    int indice = 0;
    for (int i = 1; i < y; i++) {
        if (valores[i] > valores[indice]) indice = i;
    }
    return indice;
}

// Menor Nota
int localizarMenor(float *valores, int y) {
    int indice = 0;
    for (int i = 1; i < y; i++) {
        if (valores[i] < valores[indice]) indice = i;
    }
    return indice;
}

// Acima da média
int contarAcimaMedia(float *valores, int y, float media) {
    int cont = 0;
    for (int i = 0; i < y; i++) {
        if (valores[i] > media) cont++;
    }
    return cont;
}

// Ordenação para Mediana/Moda
void ordenar(float *valores, int y) {
    float aux;
    for (int j = 0; j < y - 1; j++ ) {
        for (int i = 0; i < y - j - 1; i++) {
            if (valores[i] > valores[i + 1]) {
                aux = valores[i];
                valores[i] = valores[i + 1];
                valores[i + 1] = aux;
            }
        }
    }
}

float calcularMediana(float *valores, int y) {
    float *copia = malloc(y * sizeof(float)); 
    for (int i = 0; i < y; i++) copia[i] = valores[i];
    ordenar(copia, y);

    float res;
    if (y % 2 != 0) res = copia[y / 2];
    else res = (copia[y / 2 - 1] + copia[y / 2]) / 2.0;

    free(copia);
    return res;
}

void imprimirModa(float *valores, int y) {
    if (y == 0) return;
    float *copia = malloc(y * sizeof(float));
    for (int i = 0; i < y; i++) copia[i] = valores[i];
    ordenar(copia, y);

    int maxFrequencia = 0, frequenciaAtual = 1, qtdModas = 0;
    float modaPrincipal = copia[0];

    // Descobrir a maior frequência
    for (int i = 1; i <= y; i++) {
        if (i < y && copia[i] == copia[i - 1]) frequenciaAtual++;
        else {
            if (frequenciaAtual > maxFrequencia) maxFrequencia = frequenciaAtual;
            frequenciaAtual = 1;
        }
    }

    // Verificar se a moda é única
    frequenciaAtual = 1;
    for (int i = 1; i <= y; i++) {
        if (i < y && copia[i] == copia[i - 1]) frequenciaAtual++;
        else {
            if (frequenciaAtual == maxFrequencia) {
                qtdModas++;
                modaPrincipal = copia[i - 1];
            }
            frequenciaAtual = 1;
        }
    }

    if (qtdModas > 1 || maxFrequencia == 1 && y > 1) printf("Moda: Nao ha moda unica\n");
    else printf("Moda: %.2f\n", modaPrincipal);
    
    free(copia);
}

void imprimirRelatorio(char *titulo, float *notas, int tam) {
    float m = calcularMedia(notas, tam);
    int iMaior = localizarMaior(notas, tam);
    int iMenor = localizarMenor(notas, tam);

    printf("Relatorio %s\n", titulo);
    printf("Media: %.2f\n", m);
    printf("Maior nota: %.2f (aluno %d)\n", notas[iMaior], iMaior + 1);
    printf("Menor nota: %.2f (aluno %d)\n", notas[iMenor], iMenor + 1);
    printf("Acima da media: %d\n", contarAcimaMedia(notas, tam, m));
    printf("Mediana: %.2f\n", calcularMediana(notas, tam));
    imprimirModa(notas, tam);
    printf("\n");
}

int main() 
{
    int n, k;
    scanf("%d", &n);

    float *notas = malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        scanf("%f", &notas[i]);
    }

    imprimirRelatorio("inicial", notas, n);

    scanf("%d", &k);
    int novoTam = n + k;
    notas = realloc(notas, novoTam * sizeof(float));
    for (int i = 0; i < k; i++) scanf("%f", &notas[n + i]);

    imprimirRelatorio("atualizado", notas, novoTam);

    free(notas);
    return 0;
}
