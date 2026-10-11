#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        
        if (strs.empty()) return "";
        
        
        std::sort(strs.begin(), strs.end());
        
        
        std::string first = strs[0];
        std::string last = strs.back();
        
        std::string result = "";
        
        
        for (int i = 0; i < first.length(); i++) {
            if (first[i] != last[i]) {
                break;
            }
            result += first[i];
        }
        
        return result;
    }
};