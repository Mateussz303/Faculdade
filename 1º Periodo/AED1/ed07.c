#include "io.h"
#include <stdio.h>
#include <math.h>

// grava os primeiros x inteiros no arquivo
void writeInts(char* fileName, int x) {
    FILE* arquivo = fopen(fileName, "wt");
    int y = 0;
    for (y = 1; y <= x; y = y + 1) {
        fprintf(arquivo, "%d\n", y);
    }
    fclose(arquivo);
}

// grava n multiplos de 5 impares em ordem crescente (5, 15, 25...)
void mult5(char* fileName, int n) {
    FILE* arquivo = fopen(fileName, "wt");
    int contador = 0;
    int valor = 5;

    while (contador < n) {
        if (valor % 5 == 0 && valor % 2 != 0) {
            fprintf(arquivo, "%d\n", valor);
            contador++;
        }
        valor += 10;
    }

    fclose(arquivo);
}

// grava n multiplos de 3 pares em ordem decrescente encerrando em 6
void mult3(char* fileName, int n) {
    FILE* arquivo = fopen(fileName, "wt");
    int contador = 0;
    int valor = 6 + (n - 1) * 6;

    while (contador < n) {
        if (valor % 3 == 0 && valor % 2 == 0 && valor >= 6) {
            fprintf(arquivo, "%d\n", valor);
            contador++;
        }
        valor -= 6;
    }

    fclose(arquivo);
}

// grava n termos da sequencia de potencias de 3 (1, 3, 9, 27...)
void seq3(char* fileName, int n) {
    FILE* arquivo = fopen(fileName, "wt");
    int contador = 0;
    int valor = 1;

    while (contador < n) {
        fprintf(arquivo, "%d\n", valor);
        valor = valor * 3;
        contador++;
    }

    fclose(arquivo);
}

// grava n termos da sequencia decrescente de potencias de 5 (1/625, 1/125...)
void powmenos(char* fileName, int n) {
    FILE* arquivo = fopen(fileName, "wt");
    int contador = 0;
    int denominador = 1;
    int divisor = 1;
    int i = 0;

    // calcula o divisor inicial: 5^(n-1)
    for (i = 0; i < n - 1; i++) {
        divisor = divisor * 5;
    }

    while (contador < n) {
        fprintf(arquivo, "%d/%d\n", denominador, divisor);
        divisor = divisor / 5;
        contador++;
    }

    fclose(arquivo);
}

// grava n termos da sequencia 1, 1/x³, 1/x⁵, 1/x⁷...
void seq5(char* fileName, int n, double x) {
    FILE* arquivo = fopen(fileName, "wt");
    int contador = 0;
    int expoente = 3;

    fprintf(arquivo, "1\n"); // primeiro termo sempre é 1
    contador++;

    while (contador < n) {
        double valor = 1.0 / pow(x, expoente); // calcula 1/x^expoente
        fprintf(arquivo, "%lf\n", valor);
        expoente += 2; // expoente cresce: 3, 5, 7, 9...
        contador++;
    }

    fclose(arquivo);
}

// soma os primeiros n valores do DADOS5 (reais) e grava resultado
double somaSeq5(char* fileIn, char* fileOut, int n) {
    FILE* entrada = fopen(fileIn,  "rt");
    FILE* saida   = fopen(fileOut, "at");
    double valor  = 0.0;
    double soma   = 0.0;
    int contador  = 0;

    while (contador < n && !feof(entrada)) {
        fscanf(entrada, "%lf", &valor);
        soma += valor;
        contador++;
    }

    fprintf(saida, "n=%d => soma=%lf\n", n, soma);

    fclose(entrada);
    fclose(saida);

    return soma;
}

int maiorigual3 (const char *cadeia)
{
    int quantidade = 0;
    int i = 0;
    while (cadeia[i] != '\0')
    {
        if (cadeia[i] >= '3' && cadeia[i] <= '9')
        quantidade++;
        i++;
    }
    return quantidade;
}

int contarMaiusculas(const char *cadeia)
{
    int quantidade = 0;
    int i = 0;
    while (cadeia[i] != '\0')
    {
        if (cadeia[i] >= 'A' && cadeia[i] <= 'Z')
        quantidade++;
        i++;
    }
    return quantidade;
}

void contarMaiusculasMetodo (const char *cadeia, int *quantidade)
{
    *quantidade = contarMaiusculas(cadeia);
}
double somapowmenos(char* fileIn, char* fileOut, int n) {
    FILE* entrada   = fopen(fileIn,  "rt");
    FILE* saida     = fopen(fileOut, "at");
    int numerador   = 0;
    int denominador = 0;
    double valor    = 0.0;
    double soma     = 0.0;
    int contador    = 0;

    while (contador < n && !feof(entrada)) {
        fscanf(entrada, "%d/%d", &numerador, &denominador);
        valor = (double)numerador / (double)denominador;
        soma += valor;
        contador++;
        fprintf(saida, "n=%d => soma=%lf\n", contador, soma);
    }

    fclose(entrada);
    fclose(saida);

    return soma;
}
long long fibTermo(int n) {
    long long a = 1, b = 1;
    int i = 0;
    if (n <= 2) return 1;
    for (i = 3; i <= n; i++) {
        long long temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}
void fibonacci(char* fileOut, int n) {
    FILE* saida = fopen(fileOut, "at");
    int contador = 0;
    int indiceFib = 3;  

    fprintf(saida, "n=%d => { ", n);

    while (contador < n) {
        long long valor = fibTermo(indiceFib);
        if (contador < n - 1)
            fprintf(saida, "%lld, ", valor);
        else
            fprintf(saida, "%lld", valor);
        indiceFib += 3; 
        contador++;
    }

    fprintf(saida, " }\n");
    fclose(saida);
}


void method_01() {
    int inteiro = 0;
    IO_id("Method_01 - v0.0");
    printf("Inserir um valor inteiro: ");
    scanf("%d", &inteiro);
    mult5("DADOS1.TXT", inteiro);
    IO_pause("Apertar ENTER para continuar");
}

void method_02() {
    int inteiro = 0;
    IO_id("Method_02 - v0.0");
    printf("Inserir um valor inteiro: ");
    scanf("%d", &inteiro);
    mult3("DADOS2.TXT", inteiro);
    IO_pause("Apertar ENTER para continuar");
}

void method_03() {
    int inteiro = 0;
    IO_id("Method_03 - v0.0");
    printf("Inserir um valor inteiro: ");
    scanf("%d", &inteiro);
    seq3("DADOS3.TXT", inteiro);
    IO_pause("Apertar ENTER para continuar");
}

void method_04() {
    int inteiro = 0;
    IO_id("Method_04 - v0.0");
    printf("Inserir um valor inteiro: ");
    scanf("%d", &inteiro);
    powmenos("DADOS4.TXT", inteiro);
    IO_pause("Apertar ENTER para continuar");
}

void method_05() {
    int inteiro = 0;
    double real = 0.0;
    IO_id("Method_05 - v0.0");
    printf("Inserir um valor inteiro: ");
    scanf("%d", &inteiro);
    printf("Inserir valor real: ");
    scanf("%lf", &real);
    seq5("DADOS5.TXT", inteiro, real);
    IO_pause("Apertar ENTER para continuar");
}

void method_06() {
    int n = 0;
    IO_id("Method_06 - v0.0");
    printf("Inserir quantidade n: ");
    scanf("%d", &n);
    somaSeq5("DADOS5.TXT", "RESULTADO06.TXT", n);
    IO_pause("Apertar ENTER para continuar");
}

void method_07() {
    int n = 0;
    IO_id("Method_07 - v0.0");
    printf("Inserir quantidade n: ");
    scanf("%d", &n);
    somapowmenos("DADOS4.TXT", "RESULTADO07.TXT", n);
    IO_pause("Apertar ENTER para continuar");
}
void method_08() {
    int inteiro = 0;
    IO_id("Method_08 - v0.0");
    printf("Inserir valor inteiro: ");
    scanf("%d", &inteiro);         
    fibonacci("RESULTADO08.TXT", inteiro);
    IO_pause("Apertar ENTER para continuar");
}
void method_09() {
    char cadeia[200];
    int quantidade = 0;
    int n = 0;
    int i = 0;
    FILE *fpEntrada, *fpSaida;

    IO_id("Method_09 - v0.0");

   
    printf("Quantas cadeias deseja inserir? ");
    scanf("%d", &n);
    getchar();

  
    fpEntrada = fopen("DADOS9.TXT", "wt");
    for (i = 0; i < n; i++) {
        printf("Cadeia %d: ", i + 1);
        fgets(cadeia, sizeof(cadeia), stdin);
        fprintf(fpEntrada, "%s", cadeia);
    }
    fclose(fpEntrada);

   
    fpEntrada = fopen("DADOS9.TXT", "rt");
    fpSaida   = fopen("RESULTADO09.TXT", "wt");

    while (fgets(cadeia, sizeof(cadeia), fpEntrada) != NULL) {
        int len = 0;
        while (cadeia[len] != '\0') len++;
        if (len > 0 && cadeia[len - 1] == '\n') cadeia[len - 1] = '\0';
        if (cadeia[0] == '\0') continue;

        contarMaiusculasMetodo(cadeia, &quantidade);
        fprintf(fpSaida, "Cadeia: \"%s\" | Maiusculas: %d\n", cadeia, quantidade);
        printf("Cadeia: \"%s\" | Maiusculas: %d\n", cadeia, quantidade);
    }

    fclose(fpEntrada);
    fclose(fpSaida);

    printf("Resultados gravados em RESULTADO09.TXT\n");
    IO_pause("Apertar ENTER para continuar");
}
void method_10() {
    char *cadeia;
    int quantidade = 0;
    FILE *fpSaida;

    IO_id("Method_10 - v0.0");

    IO_flush();  // limpa o '\n' que o scanf do main deixou
    cadeia = IO_readln("Inserir cadeia: ");

    quantidade = maiorigual3(cadeia);

    fpSaida = fopen("RESULTADO10.TXT", "wt");
    fprintf(fpSaida, "Cadeia: \"%s\" | Digitos >= 3: %d\n", cadeia, quantidade);
    fclose(fpSaida);

    printf("Cadeia: \"%s\" | Digitos >= 3: %d\n", cadeia, quantidade);
    printf("Resultados gravados em RESULTADO10.TXT\n");
    IO_pause("Apertar ENTER para continuar");
}




int main() {
    int opcao = 0;

    printf("Escolha um metodo (1-10): ");
    scanf("%d", &opcao);
    printf("opcao escolhida: %d\n", opcao);

    switch (opcao) {
        case 1:  method_01(); break;
        case 2:  method_02(); break;
        case 3:  method_03(); break;
        case 4:  method_04(); break;
        case 5:  method_05(); break;
        case 6:  method_06(); break;
        case 7:  method_07(); break;
        case 8:  method_08(); break;
        case 9:  method_09(); break;
        case 10: method_10(); break;
        default: printf("Opcao invalida!\n"); break;
    }

    return 0;
}