// Just sort array and go over all elements.
// If nearby elements distinct - increase count

#include <algorithm>

int solution(vector<int> &A) {
    if(A.size() ==0) return 0;
    sort(A.begin(), A.end());
    unsigned int dist = 1;
    for(unsigned int i = 0; i < A.size()-1; ++i) {
        if(A[i]!=A[i+1]) ++dist;
    }
    return dist;
}