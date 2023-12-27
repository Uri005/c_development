#include <iostream>
#include <algorithm> // for sort
#include <array>
#include <random>    // for random_device, mt19937, and uniform_int_distribution

using namespace std;

int main() {
    // Create an array of 10 numbers and fill it with random integers
    const int range_from  = 0;
    const int range_to    = 1000;
    array<int, 10> array;

    //using std::uniform_int_distribution<int> instead rand()%*(max-min+1) + min
    random_device rand_dev;
    mt19937 generator(rand_dev());
    uniform_int_distribution<int> dstr(range_from, range_to);

    // Fill the array with random numbers acceding at the array memory location 
    for (int& number : array) {
      number = dstr(generator);
    }

    // Sort the array in numerical order
    //sort(array.begin(), array.end());

    // Display the original and sorted arrays
    cout << "Original Array: ";
    for (int number : array) {
        cout << number << " ";
    }
    cout << endl;

    cout << "Sorted Array: ";
    sort(array.begin(), array.end());
    for (int number : array) {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}