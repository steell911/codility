// The main idea is to divide input value by two 
// and check the rest. If the rest is zero, then you
// get zero and increase count. If you get one - you save count (if
// it largeer than your previous maximum) and equal count to zero. 
// Repeat it, while your value larger than zero. 

#include <iostream>

int solution(int N) {
    int total = 0;
    int count = 0;
    bool skip = (N%2 == 0); 

    while(N>0) {
        if(N%2 == 0) {
            ++count;
        }
        else {
            if(count > total) {
                total = count;
            }
            if(skip) {
                skip = false;
                total = 0;
            }
            count = 0;
        }
        N/=2;
    }
    return total;
}