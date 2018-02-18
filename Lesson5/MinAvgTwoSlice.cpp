// This is not obvious task. The main idea is to
// check pairs and tripples. It's enough. Why?
// So, if you found, for example, part of 4 elements with 
// min average, you can split it on two pairs. Five on pair and
// tripple etc. So, you need to check only pairs and tripples.

int solution(vector<int> &A) {
    if(A.size() == 2) return 0;
    unsigned int size = A.size();
    double minAverage = (static_cast<double>(A[1]+A[0]))/2;
    int firstIndex = 0;
    for(unsigned int i = 0; i<size-2; ++i) {
        if((static_cast<double>(A[i] + A[i+1]))/2 < minAverage) {
            minAverage = (static_cast<double>(A[i] + A[i+1]))/2;
            firstIndex = i;
        }
        if((static_cast<double>(A[i] + A[i+1] + A[i+2]))/3 < minAverage) {
            minAverage = (static_cast<double>(A[i] + A[i+1] + A[i+2]))/3;
            firstIndex = i;
        }
    }
    if((static_cast<double>(A[size-2] + A[size-1]))/2 < minAverage) {
        firstIndex = size-2;
    }
    return firstIndex;
}