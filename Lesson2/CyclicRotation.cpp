// Idea is to create vector with size equal to 
// input array size and then copy all values
// from input array to new array, but to the shift 
// positions. Also you need to check zero array
// and remove cycles in shift (shift > array size), if any

#include <algorithm>

vector<int> solution(vector<int> &A, int K) {
    if(A.size() == 0) return A;

    int shift = K % A.size();
    if(shift == 0) return A;
    vector<int> B;
    B.resize(0);
    B.reserve(A.size());
    copy(A.end()-shift, A.end(), std::back_inserter(B));
    copy(A.begin(), A.end()-shift, std::back_inserter(B));
    return B;
}