// Main idea is to create bools array (all values to false), where all elements
// corresponds to positions in input array (size equal to X). Yoy need to step
// by step check all positions. If position meets first time, you
// set value of this position in bools array to true and decrease count.
// If value already true it means that this position already met and you 
// don't decrease the count. If count is 0 then return number of passed
// steps.

#include <algorithm>

int solution(int X, vector<int> &A) {
    vector<bool> B(X, false);
    int count = X;
    int i = 0;
    
    for(const auto &it : A) {
        if((it <= X)&&(it > 0)) {
            if(!B[it]) {
                B[it] = true;
                --count;
            }
        }
        if(count == 0) return i;
        ++i;
    }
    return -1;
}