#include "io.h"


void printDoubleMatrix ( int rows, int columns, double matrix [ ][columns] )
{

    int x = 0;
    int y = 0;


    for ( x=0; x<rows; x=x+1 )
    {
        for ( y=0; y<columns; y=y+1 )
        {
            IO_printf ( "%8.2f\t", matrix [ x ][ y ] );
        } 
        IO_printf ( "\n" );
    } 
} 

int freadMatrixRows ( chars fileName )
{

    int n = 0;
    FILE* arquivo = fopen ( fileName, "rt" );


    IO_fscanf ( arquivo, "%d", &n );
    if ( n <= 0 )
    {
        IO_println ( "ERRO: Valor invalido." );
        n = 0;
    } 

    fclose ( arquivo );
    return ( n );
} 


int freadMatrixColumns ( chars fileName )
{

    int n = 0;
    FILE* arquivo = fopen ( fileName, "rt" );


    IO_fscanf ( arquivo, "%d", &n );
    IO_fscanf ( arquivo, "%d", &n );
    if ( n <= 0 )
    {
        IO_println ( "ERRO: Valor invalido." );
        n = 0;
    } 

    fclose ( arquivo );
    return ( n );
} 


void freadDoubleMatrix ( chars fileName, int rows, int columns,
                         double matrix [ ][columns] )
{

    int x = 0;
    int y = 0;
    int rx = 0;
    int ry = 0;
    double z = 0.0;
    FILE* arquivo = fopen ( fileName, "rt" );


    IO_fscanf ( arquivo, "%d", &rx );
    IO_fscanf ( arquivo, "%d", &ry );

    if ( rows <= 0 || rows > rx ||
         columns <= 0 || columns > ry )
    {
        IO_println ( "ERRO: Valor invalido." );
    }
    else
    {
    
        x = 0;
        while ( !feof ( arquivo ) && x < rows )
        {
            y = 0;
            while ( !feof ( arquivo ) && y < columns )
            {
                IO_fscanf ( arquivo, "%lf", &z );
                matrix [ x ][ y ] = z;
                y = y + 1;
            } 
            x = x + 1;
        } 
    } 

    fclose ( arquivo );
} 
void readPositiveDoubleMatrix ( int rows, int columns,
                                double matrix [ ][columns] )
{

    int x = 0;
    int y = 0;
    double valor = 0.0;
    chars text = IO_new_chars ( STR_SIZE );


    for ( x=0; x<rows; x=x+1 )
    {
        for ( y=0; y<columns; y=y+1 )
        {
            strcpy ( text, STR_EMPTY );
            valor = IO_readdouble ( IO_concat (
                IO_concat ( IO_concat ( text, IO_toString_d ( x ) ), ", " ),
                IO_concat ( IO_concat ( text, IO_toString_d ( y ) ), " : " ) ) );

            if ( valor < 0.0 )
            {
                IO_println ( "ERRO: Valor deve ser positivo ou zero. Usando zero." );
                valor = 0.0;
            } 

            matrix [ x ][ y ] = valor;
        } 
    } 
} 
void method_01 ( )
{

    int rows    = 0;
    int columns = 0;
    double positiveMatrix [ 10 ][ 10 ];


    IO_id ( "Method_01 - v0.0" );


    rows    = IO_readint ( "\nrows = " );
    columns = IO_readint ( "\ncolumns = " );

    if ( rows <= 0 || columns <= 0 )
    {
        IO_println ( "\nERRO: Dimensoes invalidas." );
    }
    else
    {
    
        readPositiveDoubleMatrix ( rows, columns, positiveMatrix );
    
        IO_printf ( "\n" );
        printDoubleMatrix ( rows, columns, positiveMatrix );
    } 


    IO_pause ( "Apertar ENTER para continuar" );
} 


void fprintDoubleMatrix ( chars fileName, int rows, int columns,
                          double matrix [ ][columns] )
{

    FILE* arquivo = fopen ( fileName, "wt" );
    int x = 0;
    int y = 0;


    IO_fprintf ( arquivo, "%d\n", rows );
    IO_fprintf ( arquivo, "%d\n", columns );


    for ( x=0; x<rows; x=x+1 )
    {
        for ( y=0; y<columns; y=y+1 )
        {
            IO_fprintf ( arquivo, "%lf\n", matrix [ x ][ y ] );
        } 
    } 


    fclose ( arquivo );
} 


void method_02 ( )
{

    int rows    = 0;
    int columns = 0;
    double positiveMatrix [ 10 ][ 10 ];


    IO_id ( "Method_02 - v0.0" );


    rows    = IO_readint ( "\nrows = " );
    columns = IO_readint ( "\ncolumns = " );

    if ( rows <= 0 || columns <= 0 )
    {
        IO_println ( "\nERRO: Dimensoes invalidas." );
    }
    else
    {
   
        readPositiveDoubleMatrix ( rows, columns, positiveMatrix );

    
        fprintDoubleMatrix ( "MATRIX_01.TXT", rows, columns, positiveMatrix );
        IO_println ( "\nMatriz gravada em MATRIX_01.TXT" );

    
        rows    = freadMatrixRows    ( "MATRIX_01.TXT" );
        columns = freadMatrixColumns ( "MATRIX_01.TXT" );
        freadDoubleMatrix ( "MATRIX_01.TXT", rows, columns, positiveMatrix );

  
        IO_printf ( "\nMatriz recuperada do arquivo:\n" );
        printDoubleMatrix ( rows, columns, positiveMatrix );
    }


    IO_pause ( "Apertar ENTER para continuar" );
} 


void printDiagonalDoubleMatrix ( int rows, int columns,
                                 double matrix [ ][columns] )
{

    int x = 0;


    if ( rows != columns || rows <= 0 )
    {
        IO_println ( "ERRO: Matriz deve ser quadrada." );
    }
    else
    {

        for ( x=0; x<rows; x=x+1 )
        {
            IO_printf ( "%8.2f\n", matrix [ x ][ x ] );
        } 
    } 
} 


void method_03 ( )
{

    int rows    = 0;
    int columns = 0;
    double positiveMatrix [ 10 ][ 10 ];


    IO_id ( "Method_03 - v0.0" );


    rows    = IO_readint ( "\nrows = " );
    columns = IO_readint ( "\ncolumns = " );

    if ( rows <= 0 || columns <= 0 )
    {
        IO_println ( "\nERRO: Dimensoes invalidas." );
    }
    else
    {
    
        readPositiveDoubleMatrix ( rows, columns, positiveMatrix );
    
        IO_printf ( "\nMatriz:\n" );
        printDoubleMatrix ( rows, columns, positiveMatrix );
    
        IO_printf ( "\nDiagonal principal:\n" );
        printDiagonalDoubleMatrix ( rows, columns, positiveMatrix );
    } 


    IO_pause ( "Apertar ENTER para continuar" );
} 
void printSDiagonalDoubleMatrix ( int rows, int columns,
                                  double matrix [ ][columns] )
{

    int x = 0;


    if ( rows != columns || rows <= 0 )
    {
        IO_println ( "ERRO: Matriz deve ser quadrada." );
    }
    else
    {
    
        for ( x=0; x<rows; x=x+1 )
        {
            IO_printf ( "%8.2f\n", matrix [ x ][ columns - 1 - x ] );
        } 
    } 
} 


void method_04 ( )
{

    int rows    = 0;
    int columns = 0;
    double positiveMatrix [ 10 ][ 10 ];


    IO_id ( "Method_04 - v0.0" );


    rows    = IO_readint ( "\nrows = " );
    columns = IO_readint ( "\ncolumns = " );

    if ( rows <= 0 || columns <= 0 )
    {
        IO_println ( "\nERRO: Dimensoes invalidas." );
    }
    else
    {

        readPositiveDoubleMatrix ( rows, columns, positiveMatrix );

        IO_printf ( "\nMatriz:\n" );
        printDoubleMatrix ( rows, columns, positiveMatrix );

        IO_printf ( "\nDiagonal secundaria:\n" );
        printSDiagonalDoubleMatrix ( rows, columns, positiveMatrix );
    } 


    IO_pause ( "Apertar ENTER para continuar" );
} 


void printLDTriangleDoubleMatrix ( int rows, int columns,
                                   double matrix [ ][columns] )
{

    int x = 0;
    int y = 0;


    if ( rows != columns || rows <= 0 )
    {
        IO_println ( "ERRO: Matriz deve ser quadrada." );
    }
    else
    {
    
        for ( x=0; x<rows; x=x+1 )
        {
            for ( y=0; y<columns; y=y+1 )
            {
                if ( x > y )
                {
                    IO_printf ( "%8.2f\t", matrix [ x ][ y ] );
                } 
            } 
            IO_printf ( "\n" );
        } 
    } 
}


void method_05 ( )
{

    int rows    = 0;
    int columns = 0;
    double positiveMatrix [ 10 ][ 10 ];


    IO_id ( "Method_05 - v0.0" );


    rows    = IO_readint ( "\nrows = " );
    columns = IO_readint ( "\ncolumns = " );

    if ( rows <= 0 || columns <= 0 )
    {
        IO_println ( "\nERRO: Dimensoes invalidas." );
    }
    else
    {

        readPositiveDoubleMatrix ( rows, columns, positiveMatrix );

        IO_printf ( "\nMatriz:\n" );
        printDoubleMatrix ( rows, columns, positiveMatrix );

        IO_printf ( "\nAbaixo da diagonal principal:\n" );
        printLDTriangleDoubleMatrix ( rows, columns, positiveMatrix );
    } 


    IO_pause ( "Apertar ENTER para continuar" );
} 


void printLUTriangleDoubleMatrix ( int rows, int columns,
                                   double matrix [ ][columns] )
{

    int x = 0;
    int y = 0;


    if ( rows != columns || rows <= 0 )
    {
        IO_println ( "ERRO: Matriz deve ser quadrada." );
    }
    else
    {
   
        for ( x=0; x<rows; x=x+1 )
        {
            for ( y=0; y<columns; y=y+1 )
            {
                if ( x < y )
                {
                    IO_printf ( "%8.2f\t", matrix [ x ][ y ] );
                } 
            } 
            IO_printf ( "\n" );
        } 
    } 
} 


void method_06 ( )
{

    int rows    = 0;
    int columns = 0;
    double positiveMatrix [ 10 ][ 10 ];


    IO_id ( "Method_06 - v0.0" );


    rows    = IO_readint ( "\nrows = " );
    columns = IO_readint ( "\ncolumns = " );

    if ( rows <= 0 || columns <= 0 )
    {
        IO_println ( "\nERRO: Dimensoes invalidas." );
    }
    else
    {

        readPositiveDoubleMatrix ( rows, columns, positiveMatrix );
  
        IO_printf ( "\nMatriz:\n" );
        printDoubleMatrix ( rows, columns, positiveMatrix );

        IO_printf ( "\nAcima da diagonal principal:\n" );
        printLUTriangleDoubleMatrix ( rows, columns, positiveMatrix );
    } 


    IO_pause ( "Apertar ENTER para continuar" );
} 
void printSLDTriangleDoubleMatrix ( int rows, int columns,
                                    double matrix [ ][columns] )
{

    int x = 0;
    int y = 0;


    if ( rows != columns || rows <= 0 )
    {
        IO_println ( "ERRO: Matriz deve ser quadrada." );
    }
    else
    {
   
        for ( x=0; x<rows; x=x+1 )
        {
            for ( y=0; y<columns; y=y+1 )
            {
                if ( x + y >= columns - 1 )
                {
                    IO_printf ( "%8.2f\t", matrix [ x ][ y ] );
                } 
            } 
            IO_printf ( "\n" );
        } 
    } 
} 


void method_07 ( )
{

    int rows    = 0;
    int columns = 0;
    double positiveMatrix [ 10 ][ 10 ];


    IO_id ( "Method_07 - v0.0" );


    rows    = IO_readint ( "\nrows = " );
    columns = IO_readint ( "\ncolumns = " );

    if ( rows <= 0 || columns <= 0 )
    {
        IO_println ( "\nERRO: Dimensoes invalidas." );
    }
    else
    {

        readPositiveDoubleMatrix ( rows, columns, positiveMatrix );
    
        IO_printf ( "\nMatriz:\n" );
        printDoubleMatrix ( rows, columns, positiveMatrix );
    
        IO_printf ( "\nAbaixo e na diagonal secundaria:\n" );
        printSLDTriangleDoubleMatrix ( rows, columns, positiveMatrix );
    } 


    IO_pause ( "Apertar ENTER para continuar" );
} 
void printSLUTriangleDoubleMatrix ( int rows, int columns,
                                    double matrix [ ][columns] )
{

    int x = 0;
    int y = 0;


    if ( rows != columns || rows <= 0 )
    {
        IO_println ( "ERRO: Matriz deve ser quadrada." );
    }
    else
    {
    
        for ( x=0; x<rows; x=x+1 )
        {
            for ( y=0; y<columns; y=y+1 )
            {
                if ( x + y <= columns - 1 )
                {
                    IO_printf ( "%8.2f\t", matrix [ x ][ y ] );
                }
            } 
            IO_printf ( "\n" );
        } 
    } 
} 


void method_08 ( )
{

    int rows    = 0;
    int columns = 0;
    double positiveMatrix [ 10 ][ 10 ];


    IO_id ( "Method_08 - v0.0" );


    rows    = IO_readint ( "\nrows = " );
    columns = IO_readint ( "\ncolumns = " );

    if ( rows <= 0 || columns <= 0 )
    {
        IO_println ( "\nERRO: Dimensoes invalidas." );
    }
    else
    {

        readPositiveDoubleMatrix ( rows, columns, positiveMatrix );
  
        IO_printf ( "\nMatriz:\n" );
        printDoubleMatrix ( rows, columns, positiveMatrix );
    
        IO_printf ( "\nAcima e na diagonal secundaria:\n" );
        printSLUTriangleDoubleMatrix ( rows, columns, positiveMatrix );
    } 


    IO_pause ( "Apertar ENTER para continuar" );
} 
bool allZerosLTriangleDoubleMatrix ( int rows, int columns,
                                     double matrix [ ][columns] )
{

    bool result = true;
    int x = 0;
    int y = 0;


    if ( rows != columns || rows <= 0 )
    {
        IO_println ( "ERRO: Matriz deve ser quadrada." );
        result = false;
    }
    else
    {
   
        x = 0;
        while ( x < rows && result )
        {
            y = 0;
            while ( y < columns && result )
            {
                if ( x > y )
                {
                    result = result && ( matrix [ x ][ y ] == 0.0 );
                } 
                y = y + 1;
            } 
            x = x + 1;
        } 
    } 

    return ( result );
}


void method_09 ( )
{

    int rows    = 0;
    int columns = 0;
    double positiveMatrix [ 10 ][ 10 ];


    IO_id ( "Method_09 - v0.0" );


    rows    = IO_readint ( "\nrows = " );
    columns = IO_readint ( "\ncolumns = " );

    if ( rows <= 0 || columns <= 0 )
    {
        IO_println ( "\nERRO: Dimensoes invalidas." );
    }
    else
    {
    
        readPositiveDoubleMatrix ( rows, columns, positiveMatrix );
   
        IO_printf ( "\nMatriz:\n" );
        printDoubleMatrix ( rows, columns, positiveMatrix );
   
        IO_printf ( "\nTodos zeros abaixo da diagonal principal = %d\n",
            allZerosLTriangleDoubleMatrix ( rows, columns, positiveMatrix ) );
    } 


    IO_pause ( "Apertar ENTER para continuar" );
} 


bool allZerosUTriangleDoubleMatrix ( int rows, int columns,
                                     double matrix [ ][columns] )
{

    bool result = true;
    int x = 0;
    int y = 0;


    if ( rows != columns || rows <= 0 )
    {
        IO_println ( "ERRO: Matriz deve ser quadrada." );
        result = false;
    }
    else
    {
   
        x = 0;
        while ( x < rows && result )
        {
            y = 0;
            while ( y < columns && result )
            {
                if ( x < y )
                {
                    result = result && ( matrix [ x ][ y ] == 0.0 );
                } 
                y = y + 1;
            } 
            x = x + 1;
        } 
    } 

    return ( result );
} 


void method_10 ( )
{

    int rows    = 0;
    int columns = 0;
    double positiveMatrix [ 10 ][ 10 ];


    IO_id ( "Method_10 - v0.0" );


    rows    = IO_readint ( "\nrows = " );
    columns = IO_readint ( "\ncolumns = " );

    if ( rows <= 0 || columns <= 0 )
    {
        IO_println ( "\nERRO: Dimensoes invalidas." );
    }
    else
    {
  
        readPositiveDoubleMatrix ( rows, columns, positiveMatrix );
   
        IO_printf ( "\nMatriz:\n" );
        printDoubleMatrix ( rows, columns, positiveMatrix );
    
        IO_printf ( "\nTodos zeros acima da diagonal principal = %d\n",
            allZerosUTriangleDoubleMatrix ( rows, columns, positiveMatrix ) );
    } 


    IO_pause ( "Apertar ENTER para continuar" );
} 


int main ( )
{

    int opcao = 0;


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
