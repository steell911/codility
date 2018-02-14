// Main idea is to sort array and then find neighbors
// difference between wich more than one (also check front and 
// back elements). Also check zero and one sizes arrays.

#include <algorithm>

int solution(vector<int> &A) {
    if(A.size() == 0) return 1;
    if(A.size() == 1) return A[0]==1 ? 2 : 1;
    sort(A.begin(), A.end());
    if(A[0] != 1) return 1;
    if(static_cast<unsigned int>(A[A.size()-1]) != A.size()+1) return A.size()+1;
    for(unsigned int i = 0; i<(A.size()-1); ++i) {
        if(A[i+1] - A[i] > 1) return A[i]+1;
    }
    return 0;
}