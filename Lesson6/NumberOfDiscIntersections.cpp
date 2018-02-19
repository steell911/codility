// This is the most hard task if compare to previous
// The main idea is to create two additional arrays:
// one with left edges of circles and the other one with the right edges.
// Next we need to sort both of this arrays and create values of leftIndex,
// rightIndex and result.
// Next we go over this arrays (1 -> N) and at each step you need
// to find circles, which left edges more left then right edge of
// circle on this step

#include <algorithm>

int solution(vector<int> &A) {
    auto size = A.size();
    if(size < 2) return 0;
    vector<long int> left(size, 0), right(size, 0);
    for(unsigned int i = 0; i < size; ++i) {
        left[i] = static_cast<long int>(i) - static_cast<long int>(A[i]);
        right[i] = static_cast<long int>(i) + static_cast<long int>(A[i]);
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    unsigned int leftIndex = 0;
    unsigned int lastRight = 0;
    unsigned int result = 0;

    for(unsigned int i = 1; i < size; ++i) {
        if(right[i] != right[i-1]) {
            while((left[leftIndex] <= right[i-1])&&(leftIndex < size)) {
                ++leftIndex;
            }
            result += (i - lastRight)*(leftIndex - i) + (i-lastRight)*(i-lastRight-1)/2;
            lastRight = i;
        }
    }
    if(lastRight != size) result += (size-lastRight)*(size-lastRight-1)/2;

    if(result > 10'000'000) return -1;
    
    return result;
}