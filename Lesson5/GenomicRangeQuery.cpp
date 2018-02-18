// The idea is to create 4 arrays (for all nucleotids),
// wich elements will be correspond distance to the next element 
// with this nucleotid. This is impact arrays. For example if S=AGCC, 
// then new array for C=[21000], A=[03210], G=[10210]. 
// Last element is all arrays needs to solve and don't realy consider. 
// Then for all elements in P and Q you just check from small 
// to big impact arrays and choose the right. 

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    auto size = S.size();
    
    vector<int> impact(size, 0);
    vector<int> lengthA(size+1, 0);
    vector<int> lengthC(size+1, 0);
    vector<int> lengthG(size+1, 0);
    vector<int> lengthT(size+1, 0);
    
    auto decrypt = [](char c)
    {
        if(c == 'A') return 1;
        if(c == 'C') return 2;
        if(c == 'G') return 3;
        if(c == 'T') return 4;
        return 0;
    };
    
    for(unsigned int i = 0; i < size; ++i) {
        
        impact[size-i-1] = decrypt(S[size-i-1]);
        lengthA[size-i-1] = lengthA[size-i] + 1;
        lengthC[size-i-1] = lengthC[size-i] + 1;
        lengthG[size-i-1] = lengthG[size-i] + 1;
        lengthT[size-i-1] = lengthT[size-i] + 1;
        switch(impact[size-i-1]) {
            case 1: 
                lengthA[size-i-1] = 0;
                break;
            case 2:
                lengthC[size-i-1] = 0;
                break;
            case 3:
                lengthG[size-i-1] = 0;
                break;
            case 4:
                lengthT[size-i-1] = 0;
                break;
            default:
                break;
        }
    }
    
    unsigned int M = P.size();
    vector<int> result(M, 0);
    for(unsigned int j = 0; j < M; ++j) {
        auto length = Q[j]-P[j]+1;
        if(lengthA[P[j]] < length) result[j] = 1;
        else if(lengthC[P[j]] < length) result[j] = 2;
        else if(lengthG[P[j]] < length) result[j] = 3;
        else if(lengthT[P[j]] < length) result[j] = 4;
    }
   
    return result;
}