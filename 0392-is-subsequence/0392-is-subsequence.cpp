class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=0;
        int i=0;
        while(i<t.size() && j<s.size()){
            if(s[j]==t[i]){
                i++;j++;
            }
            else if(s[j]!=t[i]){
                i++;
            }
            else{
                j++;
            }
            
        }
        return j == s.size();
    }
};