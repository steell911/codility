// The main idea is to sort input array and then find element
// with no pair. Also need chek one-length array

#include <algorithm>

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    int size = A.size();
    if(size == 1) {
        return A[0];
    }
    for(int i = 0; i<((size-1)/2); ++i) {
        if(A[i*2]!=A[i*2+1]) return A[i*2];
    }
    return A[size-1];
}