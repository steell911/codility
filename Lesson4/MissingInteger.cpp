// First you need to sort array. Then create min value
// and equal it to one. Then step by step check values in array. 
// If min = value then increase min.  After all return min - 
// this is the smallest value in array.

#include <algorithm>

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    auto size = A.size();
    int min = 1;
    for(unsigned int i = 0; i<size; ++i) {
        if(A[i] == min) ++min;
    }
    return min;
}