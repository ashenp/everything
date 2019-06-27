#ifndef _EVERYTHING_ALGORITHM_SQRT
#define _EVERYTHING_ALGORITHM_SQRT
#include <iostream>
#include <complex>

using namespace std;
double binarySearchSqrt(int x) {
    bool is_positive = (x >= 0);
    x = x >= 0 ? x : 0-x;
    double left = 0;
    double right = x;
      
    while(true) {
        double y = (right-left)/2.0 + left;
        double g = y*y;
        if(abs(g - x) < 0.000001) {
            return y;   
        }
        if(g > x) {right = y;continue;}
        if(g < x) {left = y;continue;}
    }
}

double newtonSqrt() {

}





#endif
