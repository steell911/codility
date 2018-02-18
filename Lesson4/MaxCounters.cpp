// This is simple task with quite difficult 
// description (for me anyway). You need just going
// over all counters for all array values.

#include <algorithm>

vector<int> solution(int N, vector<int> &A) {
    vector<int> counters(N, 0);
    int currentMax = 0;
    int newMax = 0;
    for(const auto &it : A) {
        if((it > 0)&&(it < N + 1)) {
            auto currentCounter = counters[it-1];
            currentCounter < currentMax ? counters[it-1] = currentMax + 1 : ++counters[it-1];
            newMax = max(counters[it-1], newMax);
        }
        else if(it == N + 1) {
            currentMax = newMax;
            
        }
    }
    for(auto &it : counters) {
        if(it < currentMax) {
            it = currentMax;
        }
    }
    return counters;
}