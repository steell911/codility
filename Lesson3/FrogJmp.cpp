// Simple task, two raws. You just need subtract Y from X
// and divide result to D. Don't forget, that you need larger value.

#include <cmath>

int solution(int X, int Y, int D) {
    if(Y-X == 0) return 0;
    return ceil(static_cast<double>(Y-X)/D);
}