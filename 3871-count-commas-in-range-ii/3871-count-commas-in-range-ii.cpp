class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;
        long long threshold = 1000;

        while (n >= threshold) {
            totalCommas += (n - threshold + 1);
        
            if (threshold > LLONG_MAX / 1000) break;
            threshold *= 1000;
        }

        return totalCommas;
    }
};