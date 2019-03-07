#include "quick_sort.hpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace ::everything::algorithm;

int main(int argc, char* argv[]) {
    vector<int> vec;
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(1);
    quick_sort(vec, 0, 5);
    for(auto i : vec) {
        cout << i << ",";
    }
    cout<<endl;
    return 0;
}



