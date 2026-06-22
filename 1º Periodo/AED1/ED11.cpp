
#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include <ctime>



void pause ( std::string text )
{
    std::string dummy;
    std::cin.clear ( );
    std::cout << std::endl << text;
    std::cin.ignore ( );
    std::getline ( std::cin, dummy );
    std::cout << std::endl << std::endl;
} 


#include "myarray.hpp"
using namespace std;

Array <int> readArrayFromFile ( string fileName )
{
    Array <int> array ( 1, 0 );
    array.fread ( fileName );
    return ( array );
} 


void method_00 ( )
{
} 
void method_01 ( )
{

    int n        = 0;
    int inferior = 0;
    int superior = 0;
    int x        = 0;


    cout << endl << "Method_01 - v0.0" << endl;


    cout << endl << "Limite inferior: ";
    cin >> inferior;
    cout << endl << "Limite superior: ";
    cin >> superior;
    cout << endl << "Quantidade (N): ";
    cin >> n;

    if ( n <= 0 || inferior >= superior )
    {
        cout << endl << "ERRO: Valores invalidos." << endl;
    }
    else
    {
    
        Array <int> array ( n, 0 );
        for ( x = 0; x < n; x=x+1 )
        {
            array.set ( x, array.randomIntGenerate ( inferior, superior ) );
        } 

   
        array.print ( );
        array.fprint ( "DADOS.TXT" );
        cout << endl << "Valores gravados em DADOS.TXT" << endl;

    
        array.free ( );
    } 


    pause ( "Apertar ENTER para continuar" );
} 


void method_02 ( )
{

    int maior = 0;

    cout << endl << "Method_02 - v0.0" << endl;


    Array <int> array = readArrayFromFile ( "DADOS.TXT" );

    if ( array.getLength ( ) <= 0 )
    {
        cout << endl << "ERRO: Nao foi possivel ler o arquivo." << endl;
    }
    else
    {
   
        array.print ( );

   
        maior = array.searchFirstOdd ( );
        cout << endl << "Maior par = " << maior << endl;

   
        array.free ( );
    } 


    pause ( "Apertar ENTER para continuar" );
} 

void method_03 ( )
{

    int maior = 0;

    cout << endl << "Method_03 - v0.0" << endl;


    Array <int> array = readArrayFromFile ( "DADOS.TXT" );

    if ( array.getLength ( ) <= 0 )
    {
        cout << endl << "ERRO: Nao foi possivel ler o arquivo." << endl;
    }
    else
    {
  
        array.print ( );

    
        maior = array.searchFirstEvenx3 ( );
        cout << endl << "Maior par multiplo de 5 = " << maior << endl;

    
        array.free ( );
    }


    pause ( "Apertar ENTER para continuar" );
} 


void method_04 ( )
{

    int inicio = 0;
    int fim    = 0;
    int soma   = 0;


    cout << endl << "Method_04 - v0.0" << endl;


    Array <int> array = readArrayFromFile ( "DADOS.TXT" );

    if ( array.getLength ( ) <= 0 )
    {
        cout << endl << "ERRO: Nao foi possivel ler o arquivo." << endl;
    }
    else
    {

        array.print ( );


        cout << endl << "Posicao inicial: ";
        cin >> inicio;
        cout << endl << "Posicao final: ";
        cin >> fim;

    
        soma = array.addInterval ( inicio, fim );
        cout << endl << "Soma = " << soma << endl;


        array.free ( );
    } 


    pause ( "Apertar ENTER para continuar" );
} 


void method_05 ( )
{

    int inicio   = 0;
    int fim      = 0;
    double media = 0.0;

    cout << endl << "Method_05 - v0.0" << endl;


    Array <int> array = readArrayFromFile ( "DADOS.TXT" );

    if ( array.getLength ( ) <= 0 )
    {
        cout << endl << "ERRO: Nao foi possivel ler o arquivo." << endl;
    }
    else
    {

        array.print ( );


        cout << endl << "Posicao inicial: ";
        cin >> inicio;
        cout << endl << "Posicao final: ";
        cin >> fim;


        media = array.averageInterval ( inicio, fim );
        cout << endl << "Media = " << media << endl;


        array.free ( );
    }


    pause ( "Apertar ENTER para continuar" );
} 


void method_06 ( )
{

    cout << endl << "Method_06 - v0.0" << endl;


    Array <int> array = readArrayFromFile ( "DADOS.TXT" );

    if ( array.getLength ( ) <= 0 )
    {
        cout << endl << "ERRO: Nao foi possivel ler o arquivo." << endl;
    }
    else
    {
   
        array.print ( );


        cout << endl << "Todos positivos e menores que 100 = "
             << array.positives ( ) << endl;


        array.free ( );
    } 


    pause ( "Apertar ENTER para continuar" );
} 


void method_07 ( )
{

    cout << endl << "Method_07 - v0.0" << endl;


    Array <int> array = readArrayFromFile ( "DADOS.TXT" );

    if ( array.getLength ( ) <= 0 )
    {
        cout << endl << "ERRO: Nao foi possivel ler o arquivo." << endl;
    }
    else
    {
   
        array.print ( );

    
        cout << endl << "Decrescente = " << array.isDecrescent ( ) << endl;

   
        array.free ( );
    } 


    pause ( "Apertar ENTER para continuar" );
} 


void method_08 ( )
{

    int procurado = 0;
    int inicio    = 0;
    int fim       = 0;


    cout << endl << "Method_08 - v0.0" << endl;


    Array <int> array = readArrayFromFile ( "DADOS.TXT" );

    if ( array.getLength ( ) <= 0 )
    {
        cout << endl << "ERRO: Nao foi possivel ler o arquivo." << endl;
    }
    else
    {

        array.print ( );

  
        cout << endl << "Valor a procurar: ";
        cin >> procurado;
        cout << endl << "Posicao inicial: ";
        cin >> inicio;
        cout << endl << "Posicao final: ";
        cin >> fim;

  
        cout << endl << "Encontrado = "
             << array.searchInterval ( procurado, inicio, fim ) << endl;


        array.free ( );
    } 


    pause ( "Apertar ENTER para continuar" );
} 


void method_09 ( )
{

    int constante = 0;
    int inicio    = 0;
    int fim       = 0;


    cout << endl << "Method_09 - v0.0" << endl;


    Array <int> array = readArrayFromFile ( "DADOS.TXT" );

    if ( array.getLength ( ) <= 0 )
    {
        cout << endl << "ERRO: Nao foi possivel ler o arquivo." << endl;
    }
    else
    {

        cout << endl << "Original" << endl;
        array.print ( );


        cout << endl << "Constante: ";
        cin >> constante;
        cout << endl << "Posicao inicial: ";
        cin >> inicio;
        cout << endl << "Posicao final: ";
        cin >> fim;

   
        Array <int> novo = array.scalar ( constante, inicio, fim );
        cout << endl << "Resultado" << endl;
        novo.print ( );

   
        array.free ( );
        novo.free ( );
    } 


    pause ( "Apertar ENTER para continuar" );
} 
void method_10 ( )
{

    cout << endl << "Method_10 - v0.0" << endl;


    Array <int> array = readArrayFromFile ( "DADOS.TXT" );

    if ( array.getLength ( ) <= 0 )
    {
        cout << endl << "ERRO: Nao foi possivel ler o arquivo." << endl;
    }
    else
    {
    
        cout << endl << "Antes" << endl;
        array.print ( );

   
        array.sortDown ( );
        cout << endl << "Depois (decrescente)" << endl;
        array.print ( );

    
        array.free ( );
    } 


    pause ( "Apertar ENTER para continuar" );
} 



int main ( int argc, char** argv )
{

    int x = 0;


    srand ( time ( NULL ) );


    do
    {

        cout << endl << "Entrar com uma opcao 0-10: ";
        cin >> x;

        switch ( x )
        {
            case 0:  method_00 ( ); break;
            case 1:  method_01 ( ); break;
            case 2:  method_02 ( ); break;
            case 3:  method_03 ( ); break;
            case 4:  method_04 ( ); break;
            case 5:  method_05 ( ); break;
            case 6:  method_06 ( ); break;
            case 7:  method_07 ( ); break;
            case 8:  method_08 ( ); break;
            case 9:  method_09 ( ); break;
            case 10: method_10 ( ); break;
            default:
                cout << endl << "ERRO: Valor invalido." << endl;
        } 
    }
    while ( x != 0 );


    pause ( "Apertar ENTER para terminar" );
    return ( 0 );
}
