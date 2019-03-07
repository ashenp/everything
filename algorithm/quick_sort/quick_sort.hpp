#ifndef _EVERYTHING_ALGORITHM_QUICK_SORT_H
#define _EVERYTHING_ALGORITHM_QUICK_SORT_H
#include <vector>

namespace everything{

namespace algorithm{

    using namespace std;
    /**
    template <typename T>
    void quick_sort(vector<T>& vec, int left, int right);
    **/

    template <typename T>
    void quick_sort(vector<T>& vec, int left, int right) {
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
            while( i < j && vec[i] <= tmp) {
                i++; 
            }
            vec[j] = vec[i];
        }
        vec[i] = tmp;
        quick_sort(vec, left, i-1);
        quick_sort(vec, i+1, right);
    }
}

}



#endif

