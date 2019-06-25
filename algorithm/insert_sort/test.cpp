#include <iostream>

using namespace std;

void insertSort(int arr[], int size) {
    for(int i = 1; i < size; i++) {
        int pos = i-1;
        if(arr[i] < arr[pos]) {
            int x = arr[i]; 
            arr[i] = arr[pos];
            while(x < arr[pos]) {
                arr[pos+1] = arr[pos];
                pos--;   
            }
            arr[pos+1] = x; 
        } 
    } 
}

void printArr(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << ",";
    } 
    cout << endl;
}

int main(int argc, char** argv) {
    int arr[8] = {3, 1, 5, 7, 2, 4, 9, 6}; 
    insertSort(arr, 8);
    printArr(arr, 8);
    return 0;
}

