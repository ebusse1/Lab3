#include <iostream>
#include <cstdio>
#include <string>

using namespace std; 

extern "C" void find_sum(const int * data_array, int count); // Assembly function

int main(){

    //Create array to hold the integers
    int data_array[100];
    int size = 0;
    int count = 0;
    string file_name;

    //Request file name from user
    cout << "Enter file name: ";
    cin >> file_name;

    //Open the file
    FILE * my_file = fopen(file_name.c_str(), "r");

    fscanf(my_file, "%d", &size); // Load the first number into size

    //Count the ints in the file, and load them in
     while (fscanf(my_file, "%d", &data_array[count]) == 1 && count < size) {
        count++;
    }

    find_sum(data_array, count);

    return 0;
}