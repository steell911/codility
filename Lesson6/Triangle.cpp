// Firstly, you need to sort input array.
// Sufficient condition to exxisting triangle is A1 + A2 > A3,
// where A1, A2, A3 is serial nearby elements of sorting array.
// Why only this condition is enough? So, beacuse
// A3>A1 -> A2+A3>A1
// A3>A2 -> A1+A3>A2

#include <algorithm>

int solution(vector<int> &A) {
    if(A.size() < 3) return 0;
    sort(A.begin(), A.end());
    auto size = A.size();
    for(unsigned int i = 0; i<size-2; ++i) {
        if((static_cast<long int>(A[i]) + static_cast<long int>(A[i+1])) > static_cast<long int>(A[i+2])) return 1;
    }
    return 0;
}