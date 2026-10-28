class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 0 , n = s.length();
        for(int i = 0; i <n;i++){
            for(int l = i,r=i;r<n&&s[l]==s[r];r++)
               for(int l2 = l,r2 =r;l2>=0 && r2<n &&s[l2]==s[r2];l2--,r2++)
                if (r2-l2+1>maxLen) start=l2,maxLen=r2-l2+1;
        }
        return s.substr(start,maxLen);
    }
};