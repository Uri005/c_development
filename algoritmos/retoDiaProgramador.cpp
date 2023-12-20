#include <iostream>
#include <vector>

using namespace std;

void decodedText(string encodedTxt) {
    string alphabet = "abcdefghijklmnñopqrstuvwxyz".split();
    string decodedTxt = "";
    encodedTxt.toLowerCase().split("").forEach(item => {
        if (item === " ") {
            decodedTxt += item;
        }
        else if (alphabet.indexOf(item) != -1) {
            if (alphabet.indexOf(item) >= 5) {
                decodedTxt += alphabet[(alphabet.indexOf(item) - 5)];
            }
            else if (alphabet.indexOf(item) <= 4) {
                decodedTxt += alphabet[alphabet.length + alphabet.indexOf(item) - 5];
            }
        }
    });
    console.log(decodedTxt.toUpperCase());
}

void decodeMessage(){
  string alphabet = "abcdefghijklmnñopqrstuvwxyz";
}

vector<char> llenarArreglo(string str){
  vector<char> alphabet;

    for (char c : str) {
        alphabet.push_back(c);
    }
  return alphabet;
}