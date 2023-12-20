#include<iostream>

using namespace std;

class FirstClass{};

class SecondClass{
  public:
  void printArray(char msg, FirstClass arrayClass[20]);
};

void SecondClass::printArray(char msg, FirstClass arrayClass[20]){
  int limite = (sizeof(arrayClass)/sizeof(arrayClass[0]));
  for (int i = 0; i < limite; i++){
    cout<<arrayClass[i]<<endl;
  }
}

