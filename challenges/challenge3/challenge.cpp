#include<iostream>

using namespace std;

int main(int argc, char *argv[]){

  /**
   * TODO: To convert meters to fiets lets to multiple 1 mtr by 3.28084 fiets 
   * The program recive the meters desire to convert like an execution argument.
   * */


  if (argc < 2) { //verificamos que al menos se provea un parametro de ejecucion
    cerr << "Uso: Debe proporcionar un número de metros a convertir" << endl;
    return 1; // Indicar error
  } 

  // Convertimos el argumento a un número entero
    int meters = atoi(argv[1]);

  // Verificar si la conversión fue exitosa
  if (meters == 0 && argv[1][0] != '0') {
    cerr << "Error en el tipo de dato del argumento proporcionado " << endl;
    return 1; // Indicar error
  }

  float metersToFiets = meters * 3.28084;
  cout << argv[1] << " Meters are " << metersToFiets << " Fiets" << endl; 

  return 0;
}