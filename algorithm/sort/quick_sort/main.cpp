#include "quicksort.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    vector<int> vec;
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(4);
    printVector(vec);
    quickSort_2(vec, 0, 5);
    printVector(vec);
    return 0;
}



