class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = countAndSay (n-1), res = "";
        for(int i = 0,c=1;i < s.size();++i){
            if(i+1<s.size()&&s[i]==s[i+1])c++;
            else{ res += to_string(c) + s[i]; c = 1;}
        }
        return res;
    }
};