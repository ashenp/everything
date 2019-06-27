#ifndef _BUBBLE_SORT_HPP
#define _BUBBLE_SORT_HPP

#include <vector>
#include <iostream>

template<typename value_t>
void bubbleSort(std::vector<value_t>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size() - i ; j++) {
            if (vec[j-1] > vec[j] ) {
               std::swap(vec[j-1], vec[j]);   
            }
        }
    }
}

template<typename value_t>
void printVector(std::vector<value_t>& vec) {
    for(auto i : vec) {
        std::cout << i << " , ";
    } 
    std::cout << std::endl;
}

#endif

