#include <iostream>
#include <vector>
#include <random>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]){

  static int min_range_generator = 0;
  static int max_range_generator = 20;
  static int size_array = 50;
  
  //Generador de numeros aleatorios (device - generator - uniform distribution)
  random_device device;
  mt19937 generator(device());
  uniform_int_distribution<int> dstr (min_range_generator, max_range_generator);

  // generar un vector y llenarlo
  vector<int> array;
  for(int i=0; i< size_array; i++){
    array.push_back(dstr(generator));
  }

  /**
   * Contar la frecuencia de un elemento en el arreglo con unordered_map
   * Como un elemento clave valor, clave el elemento del array 
   * valor el numero de veces que aparece en el arreglo
   * */
  unordered_map<int,int> frecuency_map;
  for(int element : array){
    frecuency_map[element]++;
  }

  //Mostramos el arreglo
  cout << "Arreglo original: " << endl;
  for(int element : array){
    cout << element << " ";
  }
  cout << "\n" << endl;

  vector<pair<int, int>> descendent_ordered_vector;
  vector<pair<int, int>> ascendent_ordered_vector;

  //Mostramos entradas duplicadas
  cout << "Elementos duplicados" << endl;
  for(const auto& pair : frecuency_map){
    if(pair.second > 1){ //Mostramos solo entradas duplicadas, si no hay duplicados en el arreglo no se muestra
      cout << pair.first << " - " << pair.second << "\n";
      descendent_ordered_vector.push_back({pair.first,pair.second}); //agregamos los elementos al vector que ordenaremos de forma descendiente posteriormente
      ascendent_ordered_vector.push_back({pair.first,pair.second}); //agregamos los elementos al vector que ordenaremos de forma ascendente posteriormente
    }
  }

  //ordenamos el vector descendent_ordered_vector
  sort(descendent_ordered_vector.begin(), descendent_ordered_vector.end(), [](const auto& a, auto& b){
    return a.second > b.second;
  });

  //ordenamos el vector ascendent_ordered_vector
  sort(ascendent_ordered_vector.begin(), ascendent_ordered_vector.end(), [](const auto& a, const auto& b){
    return a.second < b.second;
  });

  cout << "\n" << endl;

  cout << "Arreglo ordenado ascendentemente:" << endl;
  for(const auto& element : ascendent_ordered_vector){
    cout << element.first << " - " << element.second << endl;
  }

  cout << "\n" << endl;

  //Mostramos los datos en los arreglos ordenados 
  cout << "Arreglo ordenado descendentemente: " << endl;
  for(const auto& element : descendent_ordered_vector){
    cout << element.first << " - " << element.second << endl;
  }

  return 0;
}