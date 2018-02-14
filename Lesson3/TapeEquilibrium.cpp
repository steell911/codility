// Firstly you need to solve sum of all array values.
// Next step by step, element by element substract values from
// the sum and compare with minimum sum. If it smaller, then 
// change minimum sum to new. After all return minimum sum.
// Don't forget return zero element if one size array.

#include <algorithm>
#include <numeric>
#include <cmath>

int solution(vector<int> &A) {
    if(A.size() == 1) return A[0];

    int sum = accumulate(A.begin(), A.end(), 0);
    int minSum = numeric_limits<int>::max();
    for(int i = (A.size()-1); i>0; --i)
    {
        sum -= A[i]*2;
        if(abs(sum) < minSum) minSum = abs(sum);
    }
    return minSum;
}