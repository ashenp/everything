#include <iostream>
#include <vector>
#include <set>
#include <stdlib.h>
#include <ctime>

using namespace std;

vector<double> hongbao(int money, int num) {
    money *= 100;
    set<int> line_set;
    line_set.insert(0);
    line_set.insert(money);

    int total_line_num = num - 1;
    int current_num = 0;
    
    srand((unsigned int)time(NULL));
    while(current_num < total_line_num) {
        int line_value = rand() % money;
        if(line_set.find(line_value) != line_set.end()) {
            continue;
        } 
        line_set.insert(line_value);
        current_num++;
        cout << "line_value:" << line_value << ","; 
    }    
    cout << endl;
    
    set<int>::iterator iter = line_set.begin();
    set<int>::iterator iter_before;
    iter++;
    vector<double> hongbao_vector;
    while(iter != line_set.end()) {
        iter_before = --iter; 
        iter++;
        int money = *iter - *iter_before;
        hongbao_vector.push_back((double)money/100);
        iter++;
    } 
    return hongbao_vector;
}

void printVector(vector<double> v) {
    for(auto i : v) {
        cout << i << ",";
    }
    cout << endl;
}


int main(int argc, char** argv) {
    vector<double> v1 = hongbao(100, 2);
    cout << "100块, 2人" << endl;
    printVector(v1);
    cout << endl;
    cout << endl;
    vector<double> v2 = hongbao(100, 3);
    cout << "100块, 3人" << endl;
    printVector(v2);
    cout << endl;
    cout << endl;
    vector<double> v3 = hongbao(100, 4);
    cout << "100块, 4人" << endl;
    printVector(v3);
    cout << endl;
    cout << endl;
    vector<double> v3 = hongbao(100, 4);
    cout << "100块, 4人" << endl;
    printVector(v3);
    cout << endl;
    cout << endl;

    return 0;

}
