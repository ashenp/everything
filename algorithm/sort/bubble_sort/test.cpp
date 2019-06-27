#include "bubblesort.hpp"

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
    bubbleSort(vec);
    printVector(vec);
    return 0;
}



