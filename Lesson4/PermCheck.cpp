// To check array on permutation you need sort it
// and then step by step, check pairs of between elements.
// If difference between then more than one - this array is
// permutation. Don't also forget check first element and
// one size array.

#include <algorithm>

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    auto size = A.size();
    for(unsigned int i = 0; i<(size-1); ++i) {
        if(A[i+1] - A[i] != 1) return 0;
    }
    return A[0]==1 ? 1 : 0;
}