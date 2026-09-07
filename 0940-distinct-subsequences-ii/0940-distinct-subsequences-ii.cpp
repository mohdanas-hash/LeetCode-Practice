class Solution {
public:
    int distinctSubseqII(string s) {
        long long mod = 1e9 + 7;
        vector<long long> last(26, 0);
        long long current_total = 0;
        
        for (char c : s) {
            int idx = c - 'a';
            long long new_subseqs = (current_total + 1) % mod;
            long long added = (new_subseqs - last[idx] + mod) % mod;
            
            current_total = (current_total + added) % mod;
            last[idx] = (last[idx] + added) % mod;
        }
        
        return current_total;
    }
};