#ifndef _QUICKSORT_HPP
#define _QUICKSORT_HPP

#include <iostream>
#include <vector>
using namespace std;

template<typename T> 
void printVector(const vector<T>& vec) {
    for(auto x:vec) {
        cout << x << " , ";
    }
    cout << endl;
}

template<typename T> 
void quickSort(vector<T>& vec, int left, int right) {    
    if(left >= right) {
            return; 
    }
    int i = left;
    int j = right;
    T tmp = vec[left];  
    
    while(i < j) {
        while( i < j && vec[j] >= tmp) {
            j--; 
        }
        vec[i] = vec[j];
        printVector(vec);
        while( i < j && vec[i] <= tmp) {
            i++; 
        }
        vec[j] = vec[i];
        printVector(vec);
    }
    vec[i] = tmp;
    printVector(vec);
    quickSort(vec, left, i-1);
    quickSort(vec, i+1, right);

}

template <typename T>
void quickSort_2(vector<T>& vec, int left, int right) {
    if(left >= right) {
        return; 
    }
    int i = left;
    int j = right;
    T tmp = vec[right];  
    
    while(i < j) {
        while( i < j && vec[i] <= tmp) {
            i++; 
        }
        while( i < j && vec[j] >= tmp) {
            j--; 
        }
        if(vec[i] > tmp && vec[j] < tmp) swap(vec[i], vec[j]);
    }
    swap(vec[i], vec[right]);
    quickSort_2(vec, left, i-1);
    quickSort_2(vec, i+1, right);
}











#endif
