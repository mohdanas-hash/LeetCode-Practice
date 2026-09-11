class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> unique_evens;
        int n = digits.size();
        
        for (int i = 0; i < n; ++i) {
            if (digits[i] == 0) continue; 
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) continue;
                    if (digits[k] % 2 != 0) continue; 
                    
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    unique_evens.insert(num);
                }
            }
        }
        
        return unique_evens.size();
    }
};