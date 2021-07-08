class Solution {
public:
    int hammingWeight(uint32_t n) {
        string binary = bitset<128>(n).to_string();
        int ctr = 0;
        for(auto i: binary) {
            if(i == '1')
                ctr++;
        }
        return ctr;
    }
};