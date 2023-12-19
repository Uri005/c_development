#include<iostream>

using namespace std;

class MyClass{
  public:
  void printMembers();
  friend void fiendlyFunction(int x, MyClass& mc); //Se usa la palabra friend y uno de los parámetros es una referencia a la clase MiClase
  private:
  int a;
};

void MyClass::printMembers(){
  cout<<"The 'a' value is: " <<a<<endl;
}

void fiendlyFunction(int x, MyClass& mc){
  mc.a = x; //Acceso a un miembro privado del objeto mc de la clase MiClase
}

int main(){
  MyClass obj;
  fiendlyFunction(5, obj);
  obj.printMembers();

  return 0;
}