#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
  //Creamos instancia de la clase Solution
  Solution solution;

  //Creamos los diccionarios que enviaremos como parametro al metodo "mergeDictionaryFunctions"
  unordered_map<int,int> dictionary1 = {{1, 10}, {10, 100}};
  unordered_map<int,int> dictioanry2 = {{2, 20}, {20, 200}};
  unordered_map<int,int> dictioanry3 = {{3, 30}, {30, 300}};
  vector<unordered_map<int,int>> dictionaryVectors = {dictionary1, dictioanry2, dictioanry3};

  unordered_map<int, int> dictionMergedResult = solution.mergeDictionaryFunctions(dictionaryVectors);
  
  //for(const auto& entry : dictionMergedResult){
    //cout << "{" << entry.first ": " << entry.second << "} ";
  //}


  return 0;
}

class Solution{
	public:
  //En c++ se usa unordered_map como una forma eficiente de representar diccionarios (campos CLAVE - VALOR)
		unordered_map<int, int> mergeDictionaryFunctions(const vector<unordered_map<int, int>> &dicts){
			//IMPLEMENTAMOS LA LOGICA PARA COMBINAR LOS DICCIONARIOS
			unordered_map<int, int> mergedDictionary;
      int i = 0;
			for(const auto& dict : dicts){
        for(const auto& entry : dict){
          cout << "\n\n Interaction " << i << "\n";
          cout << "mergedDictionary " << mergedDictionary[entry.first] << ", " << mergedDictionary[entry.second] << "\n\n";
          cout << entry.first << ", " << entry.second << "\n\n";
					mergedDictionary[entry.first] = entry.second;
          cout << "mergedDictionary " << mergedDictionary[entry.first] << ", " << mergedDictionary[entry.second] << "\n\n";
          i++;
        }
			}
			return mergedDictionary;
		}
};