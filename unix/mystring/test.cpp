#include <iostream>
#include "include/String.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    String b = "abc"; 
    b.append("xyz");
    cout << b << endl;
    b = b + "hehe";
    cout << b << endl;
    return 0;
}
