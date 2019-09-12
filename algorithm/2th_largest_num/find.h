#ifndef _FIND_2TH_LARGEST
#define _FIND_2TH_LARGEST
#include <list>

int find(const list<int>& arr) {
    int max = arr[0];
    int second_max = 0x80000000;
    
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] > max) {
            second_max = max;
            max = arr[i]; 
        }  else if(arr[i] >= second_max){
            second_max = arr[i]; 
        }
    }
    return second_max;
}



#endif
