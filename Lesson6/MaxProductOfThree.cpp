// First you need to sort input array, and then 
// it is only two variants for maximum multiplication:
// 1. Last three elements
// 2. Two first (if they < 0) and last

#include <algorithm>
#include <cmath>

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    auto size = A.size();
    return max(A[0]*A[1]*A[size-1], A[size-3]*A[size-2]*A[size-1]);
}