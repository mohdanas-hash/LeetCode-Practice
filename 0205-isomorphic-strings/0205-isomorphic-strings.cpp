class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int map_s[256] = {0};
        int map_t[256] = {0};

        for (int i = 0; i < s.length(); i++) {
            
            if (map_s[(unsigned char)s[i]] != map_t[(unsigned char)t[i]]) {
                return false;
            }

           
            map_s[(unsigned char)s[i]] = i + 1;
            map_t[(unsigned char)t[i]] = i + 1;
        }

        return true;
    }
};