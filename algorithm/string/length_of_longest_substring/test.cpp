#include <string>
#include <iostream>
#include <vector>

using namespace std;

string length_of_longest_substring(string s) {
    vector<int> dict(256, -1);
    int max_length = 0, start = -1; 
    string res;
    for(int i = 0; i < s.size(); i++) {
        if(dict[s[i]] > start) {
            start = dict[s[i]]; 
        } 
        dict[s[i]] = i; 
        if(max_length < i - start) {
            max_length = i - start;
            res = s.substr(start+1, max_length); 
        }
    }
    return res;
}



int main(int argc, char** argv) {
    string test_str = "abcaxyz"; 
    string res_str =length_of_longest_substring(test_str);
    cout << res_str << endl;
    return 0;
}
