#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
    const int rows = 3; 
    const int cols = 4; 


    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 10;
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }


    ofstream fout("TwoDimensionalArray.dat", ios::binary);
    if (!fout.is_open()) {
        cout << "Error opening the file!" << endl;
        return 1;
    }


    for (int i = 0; i < rows; i++) {
        fout.write((char*)arr[i], cols * sizeof(int));
    }
    fout.close(); 

    // Обнулення масиву
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = 0;
        }
    }

  
    int row, col, arr_new;
    cout << "\nEnter the row index (from 0 to " << rows - 1 << "): ";
    cin >> row;
    cout << "Enter the column index (from 0 to " << cols - 1 << "): ";
    cin >> col;
    cout << "Enter the new value for the element: ";
    cin >> arr_new;

  
    fstream finout("TwoDimensionalArray.dat", ios::binary | ios::in | ios::out);
    if (!finout.is_open()) {
        cout << "Error opening the file!" << endl;
        return 1;
    }

    
    long pos = row * cols * sizeof(int) + col * sizeof(int);


    finout.seekp(pos, ios::beg);

 
    finout.write((char*)&arr_new, sizeof(arr_new));


    finout.seekg(0);

 
    for (int i = 0; i < rows; i++) {
        finout.read((char*)arr[i], cols * sizeof(int));
    }

  
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }


    finout.close();
  
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    system("pause");
}
