#include <iostream>

using namespace std;

// Nótese el uso de una referencia
void incrementa(int& i) {
  i = i + 1;
  cout << "Valor incrementado en funcion: " << i << endl;
}

int main(){
  int i = 5;
  incrementa(i);
  cout << "Valor incrementado en main: " << i << endl;
}