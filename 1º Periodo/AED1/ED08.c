#include "io.h"
#include <stdlib.h>
 
// ---------------------- funcoes auxiliares ----------------------
 
/**
   printIntArray - Mostrar arranjo com valores inteiros.
   @param n     - quantidade de valores
   @param array - grupo de valores inteiros
*/
void printIntArray ( int n, int array [ ] )
{
// definir dado local
    int x = 0;
 
// mostrar valores no arranjo
    for ( x=0; x<n; x=x+1 )
    {
        IO_printf ( "%2d: %d\n", x, array [ x ] );
    } // end for
} // end printIntArray ( )
 
/**
   lerArquivo - Ler arranjo de arquivo.
   @param n        - quantidade de valores lidos (por referencia)
   @param fileName - nome do arquivo
   @param array    - grupo de valores inteiros
*/
void lerArquivo ( int *n, chars fileName, int array [ ] )
{
// definir dados locais
    int x = 0;
    int y = 0;
    FILE* arquivo = fopen ( fileName, "rt" );
 
// ler quantidade
    IO_fscanf ( arquivo, "%d", n );
 
// ler e guardar valores
    x = 0;
    while ( ! feof ( arquivo ) && x < *n )
    {
        IO_fscanf ( arquivo, "%d", &y );
        array [ x ] = y;
        x = x + 1;
    } // end while
 
// fechar arquivo
    fclose ( arquivo );
} // end lerArquivo ( )
 
// ---------------------- exercicios ----------------------
 
/**
   lerPares - Ler tamanho e elementos pares e positivos para arranjo.
   @param n     - quantidade de valores lidos (por referencia)
   @param array - grupo de valores inteiros
*/
void lerPares ( int *n, int array [ ] )
{
// definir dados locais
    int x     = 0;
    int valor = 0;
 
// ler e validar o tamanho
    *n = IO_readint ( "Tamanho do arranjo: " );
 
    if ( *n <= 0 )
    {
        IO_println ( "ERRO: Tamanho invalido." );
        *n = 0;
    } // end if
    else
    {
    // ler e guardar valores pares e positivos
        x = 0;
        while ( x < *n )
        {
            chars text = IO_new_chars ( STR_SIZE );
            strcpy ( text, STR_EMPTY );
            valor = IO_readint ( IO_concat (
                IO_concat ( text, IO_toString_d ( x ) ), " : " ) );
 
            if ( valor > 0 && valor % 2 == 0 )
            {
                array [ x ] = valor;
                x = x + 1;
            }
            else
            {
                IO_println ( "ERRO: Valor deve ser positivo e par." );
            } // end if
        } // end while
    } // end if
} // end lerPares ( )
 
/**
   Method_01 - Ler arranjo com valores positivos e pares.
*/
void method_01 ( )
{
// definir dados
    int n = 0;
    int array [ 100 ];
 
// identificar
    IO_id ( "Method_01 - v0.0" );
 
// ler dados
    lerPares ( &n, array );
 
// mostrar dados
    if ( n > 0 )
    {
        IO_printf ( "\n" );
        printIntArray ( n, array );
    } // end if
 
// encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )
 
// -------------------------------------------------------
 
/**
   gravarParesPositivos - Ler arranjo de arquivo descartando negativos e impares.
   @param fileName - nome do arquivo
   @param n        - quantidade de valores lidos (por referencia)
   @param array    - grupo de valores inteiros
*/
void gravarParesPositivos ( chars fileName, int *n, int array [ ] )
{
// definir dados locais
    int x     = 0;
    int valor = 0;
    FILE* arquivo = fopen ( fileName, "rt" );
 
// ler a quantidade de dados
    IO_fscanf ( arquivo, "%d", n );
 
// ler e guardar apenas valores pares e positivos
    x = 0;
    while ( ! feof ( arquivo ) && x < *n )
    {
        IO_fscanf ( arquivo, "%d", &valor );
 
        if ( valor > 0 && valor % 2 == 0 )
        {
            array [ x ] = valor;
            x = x + 1;
        } // end if
    } // end while
 
// atualizar quantidade com o que foi realmente guardado
    *n = x;
 
// fechar arquivo
    fclose ( arquivo );
} // end gravarParesPositivos ( )
 
/**
   Method_02 - Ler arranjo de arquivo descartando negativos e impares.
*/
void method_02 ( )
{
// definir dados
    int n = 0;
    int array [ 100 ];
    chars fileName = IO_new_chars ( STR_SIZE );
 
// identificar
    IO_id ( "Method_02 - v0.0" );
 
// ler nome do arquivo
    fileName = IO_readln ( "Nome do arquivo: " );
 
// ler dados do arquivo
    gravarParesPositivos ( fileName, &n, array );
 
// mostrar dados
    if ( n > 0 )
    {
        IO_printf ( "\n" );
        printIntArray ( n, array );
    }
    else
    {
        IO_println ( "Nenhum valor par e positivo encontrado." );
    } // end if
 
// encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )
 
// -------------------------------------------------------
 
/**
   gerarInt - Gerar valor inteiro aleatorio dentro de um intervalo.
   @return  - valor aleatorio entre inferior e superior
   @param inferior - limite inferior do intervalo
   @param superior - limite superior do intervalo
*/
int gerarInt ( int inferior, int superior )
{
// gerar valor aleatorio dentro do intervalo
    return ( inferior + rand ( ) % ( superior - inferior + 1 ) );
} // end gerarInt ( )
 
/**
   gerarAleatorios - Gerar arranjo com valores aleatorios e gravar em arquivo.
   @param inferior - limite inferior do intervalo
   @param superior - limite superior do intervalo
   @param n        - quantidade de valores a gerar
   @param array    - grupo de valores inteiros
*/
void gerarAleatorios ( int inferior, int superior, int n, int array [ ] )
{
// definir dados locais
    int x = 0;
    FILE* arquivo = fopen ( "DADOS.TXT", "wt" );
 
// gravar quantidade
    IO_fprintf ( arquivo, "%d\n", n );
 
// gerar e gravar valores
    x = 0;
    while ( x < n )
    {
        array [ x ] = gerarInt ( inferior, superior );
        IO_fprintf ( arquivo, "%d\n", array [ x ] );
        x = x + 1;
    } // end while
 
// fechar arquivo
    fclose ( arquivo );
} // end gerarAleatorios ( )
 
/**
   Method_03 - Gerar valores aleatorios em intervalo e gravar em arquivo.
*/
void method_03 ( )
{
// definir dados
    int n        = 0;
    int inferior = 0;
    int superior = 0;
    int array [ 100 ];
 
// identificar
    IO_id ( "Method_03 - v0.0" );
 
// ler limites do intervalo
    inferior = IO_readint ( "Limite inferior: " );
    superior = IO_readint ( "Limite superior: " );
 
// ler quantidade de elementos
    n = IO_readint ( "Quantidade de valores: " );
 
// gerar e gravar valores
    if ( n <= 0 )
    {
        IO_println ( "ERRO: Quantidade invalida." );
    }
    else if ( inferior >= superior )
    {
        IO_println ( "ERRO: Intervalo invalido." );
    }
    else
    {
        gerarAleatorios ( inferior, superior, n, array );
        IO_printf ( "\n" );
        printIntArray ( n, array );
        IO_println ( "Valores gravados em DADOS.TXT" );
    } // end if
 
// encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )
 
// -------------------------------------------------------
 
/**
   acharMenorPar - Procurar o menor valor par em arranjo.
   @return  - menor valor par, ou zero se nao houver
   @param n     - quantidade de valores
   @param array - grupo de valores inteiros
*/
int acharMenorPar ( int n, int array [ ] )
{
// definir dados locais
    int menor = 0;
    int x     = 0;
 
// procurar primeiro par como referencia inicial
    x = 0;
    while ( x < n && menor == 0 )
    {
        if ( array [ x ] % 2 == 0 )
        {
            menor = array [ x ];
        } // end if
        x = x + 1;
    } // end while
 
// procurar menor par
    while ( x < n )
    {
        if ( array [ x ] % 2 == 0 && array [ x ] < menor )
        {
            menor = array [ x ];
        } // end if
        x = x + 1;
    } // end while
 
    return ( menor );
} // end acharMenorPar ( )
 
/**
   Method_04 - Procurar menor valor par em arranjo lido de arquivo.
*/
void method_04 ( )
{
// definir dados
    int n     = 0;
    int menor = 0;
    int array [ 100 ];
    chars fileName = IO_new_chars ( STR_SIZE );
 
// identificar
    IO_id ( "Method_04 - v0.0" );
 
// ler nome do arquivo
    fileName = IO_readln ( "Nome do arquivo: " );
 
// ler dados
    lerArquivo ( &n, fileName, array );
 
// mostrar dados e resultado
    if ( n > 0 )
    {
        IO_printf ( "\n" );
        printIntArray ( n, array );
        menor = acharMenorPar ( n, array );
        IO_printf ( "\nMenor par = %d\n", menor );
    }
    else
    {
        IO_println ( "ERRO: Arquivo vazio ou invalido." );
    } // end if
 
// encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )
 
// -------------------------------------------------------
 
/**
   acharMaiorParDivisivelPorTres - Procurar maior valor par multiplo de 3 e nao de 5.
   @return  - maior valor encontrado, ou zero se nao houver
   @param n     - quantidade de valores
   @param array - grupo de valores inteiros
*/
int acharMaiorParDivisivelPorTres ( int n, int array [ ] )
{
// definir dados locais
    int maior = 0;
    int x     = 0;
 
// procurar primeiro valor valido como referencia inicial
    x = 0;
    while ( x < n && maior == 0 )
    {
        if ( array [ x ] % 2 == 0 && array [ x ] % 3 == 0 && array [ x ] % 5 != 0 )
        {
            maior = array [ x ];
        } // end if
        x = x + 1;
    } // end while
 
// procurar maior valor valido
    while ( x < n )
    {
        if ( array [ x ] % 2 == 0 && array [ x ] % 3 == 0 &&
             array [ x ] % 5 != 0 && array [ x ] > maior )
        {
            maior = array [ x ];
        } // end if
        x = x + 1;
    } // end while
 
    return ( maior );
} // end acharMaiorParDivisivelPorTres ( )
 
/**
   Method_05 - Procurar maior valor par multiplo de 3 e nao de 5.
*/
void method_05 ( )
{
// definir dados
    int n     = 0;
    int maior = 0;
    int array [ 100 ];
    chars fileName = IO_new_chars ( STR_SIZE );
 
// identificar
    IO_id ( "Method_05 - v0.0" );
 
// ler nome do arquivo
    fileName = IO_readln ( "Nome do arquivo: " );
 
// ler dados
    lerArquivo ( &n, fileName, array );
 
// mostrar dados e resultado
    if ( n > 0 )
    {
        IO_printf ( "\n" );
        printIntArray ( n, array );
        maior = acharMaiorParDivisivelPorTres ( n, array );
        IO_printf ( "\nMaior par multiplo de 3 e nao de 5 = %d\n", maior );
    }
    else
    {
        IO_println ( "ERRO: Arquivo vazio ou invalido." );
    } // end if
 
// encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )
 
// -------------------------------------------------------
 
/**
   acharMedia - Determinar a media dos valores em arranjo.
   @return  - media dos valores, ou zero se arranjo vazio
   @param n     - quantidade de valores
   @param array - grupo de valores inteiros
*/
double acharMedia ( int n, int array [ ] )
{
// definir dados locais
    double soma = 0.0;
    int x       = 0;
 
// verificar se arranjo e valido
    if ( n <= 0 )
    {
        return ( 0.0 );
    } // end if
 
// somar valores
    for ( x=0; x<n; x=x+1 )
    {
        soma = soma + array [ x ];
    } // end for
 
    return ( soma / n );
} // end acharMedia ( )
 
/**
   Method_06 - Determinar media e separar valores em dois arquivos.
*/
void method_06 ( )
{
// definir dados
    int n       = 0;
    int x       = 0;
    double media = 0.0;
    int array [ 100 ];
    FILE* menores = fopen ( "MENORES.TXT", "wt" );
    FILE* maiores = fopen ( "MAIORES.TXT", "wt" );
 
// identificar
    IO_id ( "Method_06 - v0.0" );
 
// ler dados
    lerArquivo ( &n, "DADOS.TXT", array );
 
// calcular e mostrar media
    if ( n <= 0 )
    {
        IO_println ( "ERRO: Arquivo vazio ou invalido." );
    }
    else
    {
        media = acharMedia ( n, array );
        IO_printf ( "\n" );
        printIntArray ( n, array );
        IO_printf ( "\nMedia = %lf\n", media );
 
    // separar valores em arquivos
        for ( x=0; x<n; x=x+1 )
        {
            if ( array [ x ] <= media )
            {
                IO_fprintf ( menores, "%d\n", array [ x ] );
            }
            else
            {
                IO_fprintf ( maiores, "%d\n", array [ x ] );
            } // end if
        } // end for
 
        IO_println ( "Valores separados em MENORES.TXT e MAIORES.TXT" );
    } // end if
 
// fechar arquivos
    fclose ( menores );
    fclose ( maiores );
 
// encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )
 
// -------------------------------------------------------
 
/**
   estaOrdenado - Testar se arranjo esta ordenado em ordem decrescente.
   @return  - true se ordenado, false caso contrario
   @param n     - quantidade de valores
   @param array - grupo de valores inteiros
*/
bool estaOrdenado ( int n, int array [ ] )
{
// definir dados locais
    bool result = true;
    int x       = 0;
 
// testar se existe algum valor maior que o seguinte
    x = 0;
    while ( x < n-1 && result )
    {
        result = result && ( array [ x ] >= array [ x+1 ] );
        x = x + 1;
    } // end while
 
    return ( result );
} // end estaOrdenado ( )
 
/**
   Method_07 - Testar se arranjo esta ordenado em ordem decrescente.
*/
void method_07 ( )
{
// definir dados
    int n = 0;
    int array [ 100 ];
 
// identificar
    IO_id ( "Method_07 - v0.0" );
 
// ler dados
    lerArquivo ( &n, "DADOS.TXT", array );
 
// mostrar dados e resultado
    if ( n > 0 )
    {
        IO_printf ( "\n" );
        printIntArray ( n, array );
        IO_printf ( "\nOrdenado decrescente = %d\n", estaOrdenado ( n, array ) );
    }
    else
    {
        IO_println ( "ERRO: Arquivo vazio ou invalido." );
    } // end if
 
// encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )
 
// -------------------------------------------------------
 
/**
   acharValor - Procurar valor em arranjo a partir de posicao inicial.
   @return  - true se encontrado, false caso contrario
   @param procurado - valor a ser procurado
   @param inicio    - posicao inicial para a procura
   @param n         - quantidade de valores
   @param array     - grupo de valores inteiros
*/
bool acharValor ( int procurado, int inicio, int n, int array [ ] )
{
// definir dados locais
    bool result = false;
    int x       = inicio;
 
// procurar valor
    while ( x < n && ! result )
    {
        result = ( procurado == array [ x ] );
        x = x + 1;
    } // end while
 
    return ( result );
} // end acharValor ( )
 
/**
   Method_08 - Procurar valor em arranjo lido de arquivo.
*/
void method_08 ( )
{
// definir dados
    int n        = 0;
    int procurado = 0;
    int array [ 100 ];
 
// identificar
    IO_id ( "Method_08 - v0.0" );
 
// ler dados
    lerArquivo ( &n, "DADOS.TXT", array );
 
// mostrar dados e resultado
    if ( n > 0 )
    {
        IO_printf ( "\n" );
        printIntArray ( n, array );
        procurado = IO_readint ( "\nValor a procurar: " );
        IO_printf ( "\nExiste = %d\n", acharValor ( procurado, 0, n, array ) );
    }
    else
    {
        IO_println ( "ERRO: Arquivo vazio ou invalido." );
    } // end if
 
// encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )
 
// -------------------------------------------------------
 
/**
   acharPosicao - Procurar posicao de valor em arranjo a partir de posicao inicial.
   @return  - posicao onde o valor foi encontrado, ou -1 se nao houver
   @param procurado - valor a ser procurado
   @param inicio    - posicao inicial para a procura
   @param n         - quantidade de valores
   @param array     - grupo de valores inteiros
*/
int acharPosicao ( int procurado, int inicio, int n, int array [ ] )
{
// definir dados locais
    int resultado = -1;
    int x         = inicio;
 
// procurar valor
    while ( x < n && resultado == -1 )
    {
        if ( procurado == array [ x ] )
        {
            resultado = x;
        } // end if
        x = x + 1;
    } // end while
 
    return ( resultado );
} // end acharPosicao ( )
 
/**
   Method_09 - Procurar posicao de valor em arranjo lido de arquivo.
*/
void method_09 ( )
{
// definir dados
    int n         = 0;
    int procurado = 0;
    int posicao   = 0;
    int array [ 100 ];
 
// identificar
    IO_id ( "Method_09 - v0.0" );
 
// ler dados
    lerArquivo ( &n, "DADOS.TXT", array );
 
// mostrar dados e resultado
    if ( n > 0 )
    {
        IO_printf ( "\n" );
        printIntArray ( n, array );
        procurado = IO_readint ( "\nValor a procurar: " );
        posicao   = acharPosicao ( procurado, 0, n, array );
        IO_printf ( "\nPosicao = %d\n", posicao );
    }
    else
    {
        IO_println ( "ERRO: Arquivo vazio ou invalido." );
    } // end if
 
// encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )
 
// -------------------------------------------------------
 
/**
   acharQuantos - Contar quantas vezes valor aparece em arranjo a partir de posicao inicial.
   @return  - quantidade de vezes que o valor foi encontrado
   @param procurado - valor a ser procurado
   @param inicio    - posicao inicial para a procura
   @param n         - quantidade de valores
   @param array     - grupo de valores inteiros
*/
int acharQuantos ( int procurado, int inicio, int n, int array [ ] )
{
// definir dados locais
    int quantidade = 0;
    int x          = inicio;
 
// contar ocorrencias
    while ( x < n )
    {
        if ( procurado == array [ x ] )
        {
            quantidade = quantidade + 1;
        } // end if
        x = x + 1;
    } // end while
 
    return ( quantidade );
} // end acharQuantos ( )
 
/**
   Method_10 - Contar quantas vezes valor aparece em arranjo lido de arquivo.
*/
void method_10 ( )
{
// definir dados
    int n         = 0;
    int procurado = 0;
    int array [ 100 ];
 
// identificar
    IO_id ( "Method_10 - v0.0" );
 
// ler dados
    lerArquivo ( &n, "DADOS.TXT", array );
 
// mostrar dados e resultado
    if ( n > 0 )
    {
        IO_printf ( "\n" );
        printIntArray ( n, array );
        procurado = IO_readint ( "\nValor a procurar: " );
        IO_printf ( "\nQuantas vezes = %d\n", acharQuantos ( procurado, 0, n, array ) );
    }
    else
    {
        IO_println ( "ERRO: Arquivo vazio ou invalido." );
    } // end if
 
// encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_10 ( )
 
// ---------------------- principal ----------------------
 
int main ( )
{
// definir dado
    int opcao = 0;
 
// ler opcao
    IO_printf ( "Escolha um metodo (1-10): " );
    IO_scanf   ( "%d", &opcao );
    IO_printf  ( "opcao escolhida: %d\n", opcao );
 
// executar metodo escolhido
    switch ( opcao )
    {
        case  1: method_01 ( ); break;
        case  2: method_02 ( ); break;
        case  3: method_03 ( ); break;
        case  4: method_04 ( ); break;
        case  5: method_05 ( ); break;
        case  6: method_06 ( ); break;
        case  7: method_07 ( ); break;
        case  8: method_08 ( ); break;
        case  9: method_09 ( ); break;
        case 10: method_10 ( ); break;
        default: IO_printf ( "Opcao invalida!\n" ); break;
    } // end switch
 
    return ( 0 );
} // end main ( )
 