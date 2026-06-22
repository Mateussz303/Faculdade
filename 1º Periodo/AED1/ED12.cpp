
#include <iostream>
using std::cin ;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <cstdlib>
using std::rand ;
using std::srand;
#include <ctime>
#include "mymatrix.hpp"



void pause ( string mensagem )
{
 cout << endl << mensagem << endl;
 cin.ignore ( );
 cin.get ( );
} 


void preparar ( )
{

 Matrix <int> matrix1 ( 3, 3, 0 );
 Matrix <int> matrix2 ( 3, 3, 0 );

 matrix1.set ( 0, 0, 1 ); matrix1.set ( 0, 1, 2 ); matrix1.set ( 0, 2, 3 );
 matrix1.set ( 1, 0, 4 ); matrix1.set ( 1, 1, 5 ); matrix1.set ( 1, 2, 6 );
 matrix1.set ( 2, 0, 7 ); matrix1.set ( 2, 1, 8 ); matrix1.set ( 2, 2, 9 );

 matrix2.set ( 0, 0, 9 ); matrix2.set ( 0, 1, 8 ); matrix2.set ( 0, 2, 7 );
 matrix2.set ( 1, 0, 6 ); matrix2.set ( 1, 1, 5 ); matrix2.set ( 1, 2, 4 );
 matrix2.set ( 2, 0, 3 ); matrix2.set ( 2, 1, 2 ); matrix2.set ( 2, 2, 1 );

 matrix1.fprint ( "DADOS1.TXT" );
 matrix2.fprint ( "DADOS2.TXT" );
} 

void method_01 ( )
{

 int m = 0;
 int n = 0;
 int inferior = 1;
 int superior = 100;

 cout << endl << "Method_01 (1211) - v0.0" << endl;

 cout << "\nInformar quantidade de linhas (M): ";
 cin >> m;
 cout << "Informar quantidade de colunas (N): ";
 cin >> n;

 Matrix <int> matrix ( m, n, 0 );

 matrix.randomIntGenerate ( inferior, superior );

 cout << "\nMatrix (aleatoria)\n";
 matrix.print ( );

 matrix.fprintList ( "DADOS.TXT" );

 pause ( "Apertar ENTER para continuar" );
} 


void method_02 ( )
{

 Matrix <int> matrix1 ( 1, 1, 0 );
 Matrix <int> matrix2 ( 1, 1, 0 );

 cout << endl << "Method_02 (1212) - v0.0" << endl;

 matrix1 = readMatrixFromFile <int> ( "DADOS1.TXT" );

 cout << "\nMatrix_1\n";
 matrix1.print ( );

 matrix2 = matrix1.scalar ( 3 );

 cout << "\nMatrix_2 (x3)\n";
 matrix2.print ( );

 pause ( "Apertar ENTER para continuar" );
}


void method_03 ( )
{

 Matrix <int> identidade ( 3, 3, 0 );
 Matrix <int> matrix1 ( 1, 1, 0 );

 cout << endl << "Method_03 (1213) - v0.0" << endl;

 identidade.set ( 0, 0, 1 ); identidade.set ( 0, 1, 0 ); identidade.set ( 0, 2, 0 );
 identidade.set ( 1, 0, 0 ); identidade.set ( 1, 1, 1 ); identidade.set ( 1, 2, 0 );
 identidade.set ( 2, 0, 0 ); identidade.set ( 2, 1, 0 ); identidade.set ( 2, 2, 1 );

 cout << "\nMatrix identidade\n";
 identidade.print ( );

 cout << "Identidade = " << identidade.identidade ( ) << endl;

 matrix1 = readMatrixFromFile <int> ( "DADOS1.TXT" );

 cout << "\nMatrix_1\n";
 matrix1.print ( );

 cout << "Identidade = " << matrix1.identidade ( ) << endl;

 pause ( "Apertar ENTER para continuar" );
} 


void method_04 ( )
{

 Matrix <int> matrix1 ( 1, 1, 0 );
 Matrix <int> matrix2 ( 1, 1, 0 );

 cout << endl << "Method_04 (1214) - v0.0" << endl;

 matrix1 = readMatrixFromFile <int> ( "DADOS1.TXT" );
 matrix2 = readMatrixFromFile <int> ( "DADOS1.TXT" );

 cout << "\nMatrix_1\n";
 matrix1.print ( );
 cout << "\nMatrix_2\n";
 matrix2.print ( );

 cout << "Iguais = " << ( matrix1 == matrix2 ) << endl;

 matrix2 = readMatrixFromFile <int> ( "DADOS2.TXT" );

 cout << "\nMatrix_2 (outra)\n";
 matrix2.print ( );

 cout << "Iguais = " << ( matrix1 == matrix2 ) << endl;

 pause ( "Apertar ENTER para continuar" );
} 


void method_05 ( )
{

 Matrix <int> matrix1 ( 1, 1, 0 );
 Matrix <int> matrix2 ( 1, 1, 0 );
 Matrix <int> soma ( 1, 1, 0 );

 cout << endl << "Method_05 (1215) - v0.0" << endl;

 matrix1 = readMatrixFromFile <int> ( "DADOS1.TXT" );
 matrix2 = readMatrixFromFile <int> ( "DADOS2.TXT" );

 cout << "\nMatrix_1\n";
 matrix1.print ( );
 cout << "\nMatrix_2\n";
 matrix2.print ( );

 soma = matrix1.add ( matrix2 );

 cout << "\nSoma\n";
 soma.print ( );

 pause ( "Apertar ENTER para continuar" );
} 


void method_06 ( )
{

 Matrix <int> matrix1 ( 1, 1, 0 );

 cout << endl << "Method_06 (1216) - v0.0" << endl;

 matrix1 = readMatrixFromFile <int> ( "DADOS1.TXT" );

 cout << "\nMatrix_1 (antes)\n";
 matrix1.print ( );

 matrix1.addRows ( 0, 1, (-1) );

 cout << "\nMatrix_1 (depois)\n";
 matrix1.print ( );

 pause ( "Apertar ENTER para continuar" );
} 


void method_07 ( )
{

 Matrix <int> matrix1 ( 1, 1, 0 );

 cout << endl << "Method_07 (1217) - v0.0" << endl;

 matrix1 = readMatrixFromFile <int> ( "DADOS1.TXT" );

 cout << "\nMatrix_1 (antes)\n";
 matrix1.print ( );

 matrix1.subtractRows ( 0, 1, (2) );

 cout << "\nMatrix_1 (depois)\n";
 matrix1.print ( );

 pause ( "Apertar ENTER para continuar" );
} 


void method_08 ( )
{

 Matrix <int> matrix1 ( 1, 1, 0 );
 int procurado = 0;

 cout << endl << "Method_08 (1218) - v0.0" << endl;

 matrix1 = readMatrixFromFile <int> ( "DADOS1.TXT" );

 cout << "\nMatrix_1\n";
 matrix1.print ( );

 cout << "\nInformar valor procurado: ";
 cin >> procurado;

 cout << "Linha encontrada (-1 = nao encontrado) = "
 << matrix1.searchRows ( procurado ) << endl;

 pause ( "Apertar ENTER para continuar" );
} 
void method_09 ( )
{

 Matrix <int> matrix1 ( 1, 1, 0 );
 int procurado = 0;

 cout << endl << "Method_09 (1219) - v0.0" << endl;

 matrix1 = readMatrixFromFile <int> ( "DADOS1.TXT" );

 cout << "\nMatrix_1\n";
 matrix1.print ( );

 cout << "\nInformar valor procurado: ";
 cin >> procurado;

 cout << "Coluna encontrada (-1 = nao encontrado) = "
 << matrix1.searchColumns ( procurado ) << endl;

 pause ( "Apertar ENTER para continuar" );
} 



void method_10 ( )
{

 Matrix <int> matrix1 ( 1, 1, 0 );

 cout << endl << "Method_10 (1220) - v0.0" << endl;

 matrix1 = readMatrixFromFile <int> ( "DADOS1.TXT" );

 cout << "\nMatrix_1 (original)\n";
 matrix1.print ( );

 matrix1.transpose ( );

 cout << "\nMatrix_1 (transposta)\n";
 matrix1.print ( );

 pause ( "Apertar ENTER para continuar" );
} 



int main ( int argc, char** argv )
{
   
    int x = 0;
srand ( ( unsigned int ) time ( nullptr ) );
    
    do
    {
        
        cout << endl << "Entrar com uma opcao 0-10: ";
        cin >> x;

       
        switch ( x )
        {
            case 0: break;
            case 1: method_01 ( ); break;
            case 2: method_02 ( ); break;
            case 3: method_03 ( ); break;
            case 4: method_04 ( ); break;
            case 5: method_05 ( ); break;
            case 6: method_06 ( ); break;
            case 7: method_07 ( ); break;
            case 8: method_08 ( ); break;
            case 9: method_09 ( ); break;
            case 10: method_10 ( ); break;
            default: cout << endl << "ERRO: Valor invalido." << endl;
        }

    }
    while ( x != 0 );

   
    pause ( "Apertar ENTER para terminar" );
    return ( 0 );
}
