
#include "io.h"
#include <stdlib.h>
#include <time.h>
 

typedef
struct s_int_Array
{
    int length;
    ints data;
    int ix;
}
int_Array;
 
typedef int_Array* ref_int_Array;

typedef
struct s_int_Matrix
{
    int rows;
    int columns;
    ints* data;
    int ix, iy;
}
int_Matrix;
 
typedef int_Matrix* ref_int_Matrix;
 

ref_int_Array new_int_Array ( int n )
{

    ref_int_Array tmpArray = (ref_int_Array) malloc ( sizeof(int_Array) );
 
    if ( tmpArray == NULL )
    {
        IO_printf ( "\nERRO: Falta espaco.\n" );
    }
    else
    {
        tmpArray->length = 0;
        tmpArray->data   = NULL;
        tmpArray->ix     = -1;
 
        if ( n > 0 )
        {
            tmpArray->length = n;
            tmpArray->data   = (ints) malloc ( n * sizeof(int) );
            tmpArray->ix     = 0;
        } 
    } 
 
    return ( tmpArray );
} 
void free_int_Array ( ref_int_Array tmpArray )
{
    if ( tmpArray != NULL )
    {
        if ( tmpArray->data != NULL )
        {
            free ( tmpArray->data );
        } 
        free ( tmpArray );
    } 
} 
 

void printIntArray ( int_Array array )
{
    if ( array.data )
    {
        for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 )
        {
            IO_printf ( "%2d: %d\n", array.ix, array.data [ array.ix ] );
        } 
    } 
}
 

int_Array readArrayFromFile ( chars fileName )
{

    FILE* arquivo = fopen ( fileName, "rt" );
    static int_Array array;
 
    array.length = 0;
    array.data   = NULL;
    array.ix     = -1;
 
    if ( arquivo == NULL )
    {
        IO_printf ( "\nERRO: Arquivo nao encontrado.\n" );
    }
    else
    {
   
        fscanf ( arquivo, "%d", &array.length );
 
        if ( array.length <= 0 )
        {
            IO_printf ( "\nERRO: Valor invalido.\n" );
            array.length = 0;
        }
        else
        {
        
            array.data = IO_new_ints ( array.length );
 
            if ( array.data == NULL )
            {
                array.length = 0;
            }
            else
            {
            
                for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 )
                {
                    fscanf ( arquivo, "%d", &(array.data [ array.ix ]) );
                } 
                array.ix = 0;
            } 
        } 
 
        fclose ( arquivo );
    } 
    return ( array );
} 
 

ref_int_Matrix new_int_Matrix ( int rows, int columns )
{
    ref_int_Matrix tmpMatrix = (ref_int_Matrix) malloc ( sizeof(int_Matrix) );
 
    if ( tmpMatrix != NULL )
    {
        tmpMatrix->rows    = 0;
        tmpMatrix->columns = 0;
        tmpMatrix->data    = NULL;
 
        if ( rows > 0 && columns > 0 )
        {
            tmpMatrix->rows    = rows;
            tmpMatrix->columns = columns;
            tmpMatrix->data    = malloc ( rows * sizeof(ints) );
 
            if ( tmpMatrix->data )
            {
                for ( tmpMatrix->ix=0; tmpMatrix->ix<tmpMatrix->rows;
                      tmpMatrix->ix=tmpMatrix->ix+1 )
                {
                    tmpMatrix->data [ tmpMatrix->ix ] =
                        (ints) malloc ( columns * sizeof(int) );
                } 
            } 
        } 
        tmpMatrix->ix = 0;
        tmpMatrix->iy = 0;
    } 
 
    return ( tmpMatrix );
} 
 

void free_int_Matrix ( ref_int_Matrix matrix )
{
    if ( matrix != NULL )
    {
        if ( matrix->data != NULL )
        {
            for ( matrix->ix=0; matrix->ix<matrix->rows; matrix->ix=matrix->ix+1 )
            {
                free ( matrix->data [ matrix->ix ] );
            } 
            free ( matrix->data );
        } 
        free ( matrix );
    } 
} 
 

void printIntMatrix ( ref_int_Matrix matrix )
{
    if ( matrix != NULL && matrix->data != NULL )
    {
        for ( matrix->ix=0; matrix->ix<matrix->rows; matrix->ix=matrix->ix+1 )
        {
            for ( matrix->iy=0; matrix->iy<matrix->columns; matrix->iy=matrix->iy+1 )
            {
                IO_printf ( "%3d\t", matrix->data [ matrix->ix ][ matrix->iy ] );
            } 
            IO_printf ( "\n" );
        } 
    }
} 
 

ref_int_Matrix readMatrixFromFile ( chars fileName )
{

    ref_int_Matrix matrix = NULL;
    int rows    = 0;
    int columns = 0;
    FILE* arquivo = fopen ( fileName, "rt" );
 
    if ( arquivo == NULL )
    {
        IO_printf ( "\nERRO: Arquivo nao encontrado.\n" );
    }
    else
    {
        fscanf ( arquivo, "%d", &rows );
        fscanf ( arquivo, "%d", &columns );
 
        if ( rows <= 0 || columns <= 0 )
        {
            IO_printf ( "\nERRO: Valor invalido.\n" );
        }
        else
        {
            matrix = new_int_Matrix ( rows, columns );
 
            if ( matrix != NULL && matrix->data != NULL )
            {
                matrix->ix = 0;
                while ( ! feof ( arquivo ) && matrix->ix < matrix->rows )
                {
                    matrix->iy = 0;
                    while ( ! feof ( arquivo ) && matrix->iy < matrix->columns )
                    {
                        fscanf ( arquivo, "%d", &(matrix->data [ matrix->ix ][ matrix->iy ]) );
                        matrix->iy = matrix->iy + 1;
                    } 
                    matrix->ix = matrix->ix + 1;
                } 
                matrix->ix = 0;
                matrix->iy = 0;
            } 
        } 
 
        fclose ( arquivo );
    } 
 
    return ( matrix );
} 
int RandomIntGenerate ( int inferior, int superior )
{
    return ( inferior + rand ( ) % ( superior - inferior + 1 ) );
} 
void method_01 ( )
{

    int inferior = 0;
    int superior = 0;
    int n        = 0;
    ref_int_Array array = NULL;
    FILE* arquivo = NULL;
 

    IO_id ( "Method_01 - v0.0" );
 

    inferior = IO_readint ( "\nLimite inferior: " );
    superior = IO_readint ( "\nLimite superior: " );
    n        = IO_readint ( "\nQuantidade (N): " );
 
    if ( inferior >= superior || n <= 0 || superior > 106 )
    {
        IO_printf ( "\nERRO: Valores invalidos (superior deve ser <= 106).\n" );
    }
    else
    {
    
        array = new_int_Array ( n );
 
        if ( array == NULL || array->data == NULL )
        {
            IO_printf ( "\nERRO: Falta espaco.\n" );
        }
        else
        {
            for ( array->ix=0; array->ix<array->length; array->ix=array->ix+1 )
            {
                array->data [ array->ix ] = RandomIntGenerate ( inferior, superior );
            } 
 
        
            IO_printf ( "\n" );
            printIntArray ( *array );
 
        
            arquivo = fopen ( "DADOS.TXT", "wt" );
            fprintf ( arquivo, "%d\n", array->length );
            for ( array->ix=0; array->ix<array->length; array->ix=array->ix+1 )
            {
                fprintf ( arquivo, "%d\n", array->data [ array->ix ] );
            } 
            fclose ( arquivo );
 
            IO_println ( "\nValores gravados em DADOS.TXT" );
 
        
            free_int_Array ( array );
        }
    } 
 

    IO_pause ( "Apertar ENTER para continuar" );
} 
 

bool arraySearch ( int valor, int_Array array )
{

    bool result = false;
 
    if ( array.data == NULL || array.length <= 0 )
    {
        IO_printf ( "\nERRO: Nao ha' dados.\n" );
    }
    else
    {
        for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 )
        {
            if ( array.data [ array.ix ] == valor )
            {
                result = true;
            } 
        } 
    } 
 
    return ( result );
} 
 

void method_02 ( )
{

    int_Array array;
    int valor = 0;
 

    IO_id ( "Method_02 - v0.0" );
 

    array = readArrayFromFile ( "DADOS.TXT" );
 
    if ( array.data == NULL )
    {
        IO_printf ( "\nERRO: Nao foi possivel ler o arquivo.\n" );
    }
    else
    {
   
        IO_printf ( "\n" );
        printIntArray ( array );
 
    
        valor = IO_readint ( "\nValor a procurar: " );
 
    
        IO_printf ( "\nEncontrado = %d\n", arraySearch ( valor, array ) );
 
    
        free ( array.data );
    } 
 

    IO_pause ( "Apertar ENTER para continuar" );
} 
bool arrayCompare ( int_Array array1, int_Array array2 )
{

    bool result = true;
 
    if ( array1.data == NULL || array2.data == NULL ||
         array1.length != array2.length )
    {
        IO_printf ( "\nERRO: Arranjos incompativeis.\n" );
        result = false;
    }
    else
    {
        for ( array1.ix=0; array1.ix<array1.length && result; array1.ix=array1.ix+1 )
        {
            result = result && ( array1.data [ array1.ix ] == array2.data [ array1.ix ] );
        } 
    } 
 
    return ( result );
} 
 

void method_03 ( )
{

    int_Array array1;
    int_Array array2;
 

    IO_id ( "Method_03 - v0.0" );
 

    array1 = readArrayFromFile ( "DADOS1.TXT" );
    array2 = readArrayFromFile ( "DADOS2.TXT" );
 
    if ( array1.data == NULL || array2.data == NULL )
    {
        IO_printf ( "\nERRO: Nao foi possivel ler os arquivos.\n" );
    }
    else
    {
   
        IO_printf ( "\nArranjo1\n" );
        printIntArray ( array1 );
        IO_printf ( "\nArranjo2\n" );
        printIntArray ( array2 );
 
    
        IO_printf ( "\nIguais = %d\n", arrayCompare ( array1, array2 ) );
 
   
        free ( array1.data );
        free ( array2.data );
    } 

    IO_pause ( "Apertar ENTER para continuar" );
} 
 

int_Array arrayAdd ( int_Array array1, int k, int_Array array2 )
{

    static int_Array soma;
    soma.length = 0;
    soma.data   = NULL;
    soma.ix     = -1;
 
    if ( array1.data == NULL || array2.data == NULL ||
         array1.length != array2.length )
    {
        IO_printf ( "\nERRO: Arranjos incompativeis.\n" );
    }
    else
    {
        soma.length = array1.length;
        soma.data   = IO_new_ints ( soma.length );
 
        if ( soma.data != NULL )
        {
            for ( soma.ix=0; soma.ix<soma.length; soma.ix=soma.ix+1 )
            {
                soma.data [ soma.ix ] = array1.data [ soma.ix ] + k * array2.data [ soma.ix ];
            } 
        } 
    } 
 
    return ( soma );
} 

void method_04 ( )
{

    int_Array array1;
    int_Array array2;
    int_Array soma;
 

    IO_id ( "Method_04 - v0.0" );
 

    array1 = readArrayFromFile ( "DADOS1.TXT" );
    array2 = readArrayFromFile ( "DADOS2.TXT" );
 
    if ( array1.data == NULL || array2.data == NULL )
    {
        IO_printf ( "\nERRO: Nao foi possivel ler os arquivos.\n" );
    }
    else
    {

        IO_printf ( "\nArranjo1\n" );
        printIntArray ( array1 );
        IO_printf ( "\nArranjo2\n" );
        printIntArray ( array2 );
 

        soma = arrayAdd ( array1, 1, array2 );
        IO_printf ( "\nSoma\n" );
        printIntArray ( soma );
 

        free ( array1.data );
        free ( array2.data );
        if ( soma.data ) free ( soma.data );
    } 
 

    IO_pause ( "Apertar ENTER para continuar" );
} 
 

bool isArrayDecrescent ( int_Array array )
{

    bool result = true;
 
    if ( array.data == NULL || array.length <= 0 )
    {
        IO_printf ( "\nERRO: Nao ha' dados.\n" );
        result = false;
    }
    else
    {
        for ( array.ix=0; array.ix<array.length-1 && result; array.ix=array.ix+1 )
        {
            result = result && ( array.data [ array.ix ] >= array.data [ array.ix+1 ] );
        } 
    } 
 
    return ( result );
} 
 

void method_05 ( )
{

    int_Array array;
 

    IO_id ( "Method_05 - v0.0" );
 

    array = readArrayFromFile ( "DADOS.TXT" );
 
    if ( array.data == NULL )
    {
        IO_printf ( "\nERRO: Nao foi possivel ler o arquivo.\n" );
    }
    else
    {
   
        IO_printf ( "\n" );
        printIntArray ( array );
 
   
        IO_printf ( "\nDecrescente = %d\n", isArrayDecrescent ( array ) );
 
   
        free ( array.data );
    } 
 

    IO_pause ( "Apertar ENTER para continuar" );
} 
 

ref_int_Matrix matrixTranspose ( ref_int_Matrix matrix )
{

    ref_int_Matrix transposta = NULL;
 
    if ( matrix == NULL || matrix->data == NULL )
    {
        IO_printf ( "\nERRO: Nao ha' dados.\n" );
    }
    else
    {
    
        transposta = new_int_Matrix ( matrix->columns, matrix->rows );
 
        if ( transposta == NULL || transposta->data == NULL )
        {
            IO_printf ( "\nERRO: Falta espaco.\n" );
        }
        else
        {
            for ( matrix->ix=0; matrix->ix<matrix->rows; matrix->ix=matrix->ix+1 )
            {
                for ( matrix->iy=0; matrix->iy<matrix->columns; matrix->iy=matrix->iy+1 )
                {
                    transposta->data [ matrix->iy ][ matrix->ix ] =
                        matrix->data [ matrix->ix ][ matrix->iy ];
                } 
            } 
        }
    } 
 
    return ( transposta );
} 
 

void method_06 ( )
{

    ref_int_Matrix matrix = NULL;
    ref_int_Matrix transposta = NULL;
 

    IO_id ( "Method_06 - v0.0" );
 

    matrix = readMatrixFromFile ( "MATRIX1.TXT" );
 
    if ( matrix == NULL || matrix->data == NULL )
    {
        IO_printf ( "\nERRO: Nao foi possivel ler o arquivo.\n" );
    }
    else
    {
    
        IO_printf ( "\nOriginal\n" );
        printIntMatrix ( matrix );
 
    
        transposta = matrixTranspose ( matrix );
        IO_printf ( "\nTransposta\n" );
        printIntMatrix ( transposta );
 
   
        free_int_Matrix ( matrix );
        free_int_Matrix ( transposta );
    } 
 

    IO_pause ( "Apertar ENTER para continuar" );
} 
 

bool matrixZero ( ref_int_Matrix matrix )
{

    bool result = true;
 
    if ( matrix == NULL || matrix->data == NULL )
    {
        IO_printf ( "\nERRO: Nao ha' dados.\n" );
        result = false;
    }
    else
    {
        matrix->ix = 0;
        while ( matrix->ix < matrix->rows && result )
        {
            matrix->iy = 0;
            while ( matrix->iy < matrix->columns && result )
            {
                result = result && ( matrix->data [ matrix->ix ][ matrix->iy ] == 0 );
                matrix->iy = matrix->iy + 1;
            } 
            matrix->ix = matrix->ix + 1;
        } 
    } 
 
    return ( result );
} 
 

void method_07 ( )
{

    ref_int_Matrix matrix = NULL;
 

    IO_id ( "Method_07 - v0.0" );
 

    matrix = readMatrixFromFile ( "MATRIX1.TXT" );
 
    if ( matrix == NULL || matrix->data == NULL )
    {
        IO_printf ( "\nERRO: Nao foi possivel ler o arquivo.\n" );
    }
    else
    {

        IO_printf ( "\n" );
        printIntMatrix ( matrix );
 
  
        IO_printf ( "\nTodos zeros = %d\n", matrixZero ( matrix ) );
 
  
        free_int_Matrix ( matrix );
    } 
 

    IO_pause ( "Apertar ENTER para continuar" );
} 
 

bool matrixCompare ( ref_int_Matrix matrix1, ref_int_Matrix matrix2 )
{

    bool result = true;
 
    if ( matrix1 == NULL || matrix2 == NULL ||
         matrix1->data == NULL || matrix2->data == NULL ||
         matrix1->rows != matrix2->rows ||
         matrix1->columns != matrix2->columns )
    {
        IO_printf ( "\nERRO: Matrizes incompativeis.\n" );
        result = false;
    }
    else
    {
        matrix1->ix = 0;
        while ( matrix1->ix < matrix1->rows && result )
        {
            matrix1->iy = 0;
            while ( matrix1->iy < matrix1->columns && result )
            {
                result = result &&
                    ( matrix1->data [ matrix1->ix ][ matrix1->iy ] ==
                      matrix2->data [ matrix1->ix ][ matrix1->iy ] );
                matrix1->iy = matrix1->iy + 1;
            } 
            matrix1->ix = matrix1->ix + 1;
        } 
    } 
 
    return ( result );
} 
 

void method_08 ( )
{

    ref_int_Matrix matrix1 = NULL;
    ref_int_Matrix matrix2 = NULL;
 

    IO_id ( "Method_08 - v0.0" );
 

    matrix1 = readMatrixFromFile ( "MATRIX1.TXT" );
    matrix2 = readMatrixFromFile ( "MATRIX2.TXT" );
 
    if ( matrix1 == NULL || matrix2 == NULL )
    {
        IO_printf ( "\nERRO: Nao foi possivel ler os arquivos.\n" );
    }
    else
    {
    
        IO_printf ( "\nMatriz1\n" );
        printIntMatrix ( matrix1 );
        IO_printf ( "\nMatriz2\n" );
        printIntMatrix ( matrix2 );
 
   
        IO_printf ( "\nIguais = %d\n", matrixCompare ( matrix1, matrix2 ) );
 
   
        free_int_Matrix ( matrix1 );
        free_int_Matrix ( matrix2 );
    } 
 

    IO_pause ( "Apertar ENTER para continuar" );
} 
ref_int_Matrix matrixAdd ( ref_int_Matrix matrix1, int k, ref_int_Matrix matrix2 )
{

    ref_int_Matrix soma = NULL;
 
    if ( matrix1 == NULL || matrix2 == NULL ||
         matrix1->data == NULL || matrix2->data == NULL ||
         matrix1->rows != matrix2->rows ||
         matrix1->columns != matrix2->columns )
    {
        IO_printf ( "\nERRO: Matrizes incompativeis.\n" );
    }
    else
    {
        soma = new_int_Matrix ( matrix1->rows, matrix1->columns );
 
        if ( soma == NULL || soma->data == NULL )
        {
            IO_printf ( "\nERRO: Falta espaco.\n" );
        }
        else
        {
            for ( soma->ix=0; soma->ix<soma->rows; soma->ix=soma->ix+1 )
            {
                for ( soma->iy=0; soma->iy<soma->columns; soma->iy=soma->iy+1 )
                {
                    soma->data [ soma->ix ][ soma->iy ] =
                        matrix1->data [ soma->ix ][ soma->iy ] +
                        k * matrix2->data [ soma->ix ][ soma->iy ];
                } 
            } 
        } 
    } 
 
    return ( soma );
}

void method_09 ( )
{

    ref_int_Matrix matrix1 = NULL;
    ref_int_Matrix matrix2 = NULL;
    ref_int_Matrix soma    = NULL;
 

    IO_id ( "Method_09 - v0.0" );
 

    matrix1 = readMatrixFromFile ( "MATRIX1.TXT" );
    matrix2 = readMatrixFromFile ( "MATRIX2.TXT" );
 
    if ( matrix1 == NULL || matrix2 == NULL )
    {
        IO_printf ( "\nERRO: Nao foi possivel ler os arquivos.\n" );
    }
    else
    {
   
        IO_printf ( "\nMatriz1\n" );
        printIntMatrix ( matrix1 );
        IO_printf ( "\nMatriz2\n" );
        printIntMatrix ( matrix2 );
 
   
        soma = matrixAdd ( matrix1, -1, matrix2 );
        IO_printf ( "\nSoma\n" );
        printIntMatrix ( soma );
 
    
        free_int_Matrix ( matrix1 );
        free_int_Matrix ( matrix2 );
        free_int_Matrix ( soma );
    } 
 

    IO_pause ( "Apertar ENTER para continuar" );
} 
 

ref_int_Matrix matrixProduct ( ref_int_Matrix matrix1, ref_int_Matrix matrix2 )
{

    ref_int_Matrix produto = NULL;
    int z = 0;
    int soma = 0;
 
    if ( matrix1 == NULL || matrix2 == NULL ||
         matrix1->data == NULL || matrix2->data == NULL ||
         matrix1->columns != matrix2->rows )
    {
        IO_printf ( "\nERRO: Matrizes incompativeis.\n" );
    }
    else
    {
        produto = new_int_Matrix ( matrix1->rows, matrix2->columns );
 
        if ( produto == NULL || produto->data == NULL )
        {
            IO_printf ( "\nERRO: Falta espaco.\n" );
        }
        else
        {
            for ( produto->ix=0; produto->ix<produto->rows; produto->ix=produto->ix+1 )
            {
                for ( produto->iy=0; produto->iy<produto->columns; produto->iy=produto->iy+1 )
                {
                    soma = 0;
                    for ( z=0; z<matrix1->columns; z=z+1 )
                    {
                        soma = soma + matrix1->data [ produto->ix ][ z ] *
                                      matrix2->data [ z ][ produto->iy ];
                    } 
                    produto->data [ produto->ix ][ produto->iy ] = soma;
                } 
            } 
        } 
    } 
 
    return ( produto );
} 
 

void method_10 ( )
{

    ref_int_Matrix matrix1 = NULL;
    ref_int_Matrix matrix2 = NULL;
    ref_int_Matrix produto = NULL;
 

    IO_id ( "Method_10 - v0.0" );
 

    matrix1 = readMatrixFromFile ( "MATRIX1.TXT" );
    matrix2 = readMatrixFromFile ( "MATRIX2.TXT" );
 
    if ( matrix1 == NULL || matrix2 == NULL )
    {
        IO_printf ( "\nERRO: Nao foi possivel ler os arquivos.\n" );
    }
    else
    {
    
        IO_printf ( "\nMatriz1\n" );
        printIntMatrix ( matrix1 );
        IO_printf ( "\nMatriz2\n" );
        printIntMatrix ( matrix2 );
 
  
        produto = matrixProduct ( matrix1, matrix2 );
        IO_printf ( "\nProduto = Matriz1 x Matriz2\n" );
        printIntMatrix ( produto );
 
    
        free_int_Matrix ( matrix1 );
        free_int_Matrix ( matrix2 );
        free_int_Matrix ( produto );
    } 
 

    IO_pause ( "Apertar ENTER para continuar" );
} 
 

 
int main ( )
{

    int opcao = 0;
 

    srand ( time ( NULL ) );
 

    IO_printf ( "Escolha um metodo (1-10): " );
    IO_scanf   ( "%d", &opcao );
    IO_printf  ( "opcao escolhida: %d\n", opcao );
 

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
    } 
 
    return ( 0 );
} 
 