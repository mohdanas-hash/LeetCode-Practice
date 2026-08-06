class Solution {
public:
    int smallestNumber(int n, int t) {
        auto getProd = [](int x){
            int p = 1;
            for(; x; x/=10) p *= x % 10;
            return p;
        };
        while (getProd(n)%t) n++;
        return n;
    }
};