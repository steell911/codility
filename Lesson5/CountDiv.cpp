// You just need divide to K value A and value B.
// Difference between result values is the task result.

#include <algorithm>
#include <cmath>

int solution(int A, int B, int K) {
    int begin = ceil(static_cast<double>(A)/K);
    int end = floor(static_cast<double>(B)/K);
    return max(0, end - begin + 1);  
}