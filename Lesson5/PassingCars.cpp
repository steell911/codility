// Simple task. You just need to going over all
// elements and count zero and one and also pairs.
// Don't forget return -1 if overflow.

int solution(vector<int> &A) {
    long long unsigned int zeroCount = 0;
    long long unsigned int oneCount = 0;
    long long unsigned int pairInvSum = 0;
    for(const auto &it : A) {
        if(it == 0) {
            ++zeroCount;
            pairInvSum += oneCount;
        }
        else {
            ++oneCount;
        }
    }
    long long unsigned int result = zeroCount*oneCount - pairInvSum;
    if(result > 1000000000) return -1;
    return result;
}