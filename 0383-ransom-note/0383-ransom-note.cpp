class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>have;
        unordered_map<char,int>need;
        int n=magazine.size();
        int m=ransomNote.size();
        for(int i =0; i<n;i++){
            have[magazine[i]]++;
        }
        for(int i=0; i<m;i++){
            need[ransomNote[i]]++;
        }
        return func(have,need);
    }
    bool func(unordered_map<char,int>have,unordered_map<char,int>need){
        for (auto i : need) {
        char c = i.first;
        int fneed = i.second;
        int fhave = have[c];
        if (fhave < fneed) return false;
        }
        return true;
    }       
};