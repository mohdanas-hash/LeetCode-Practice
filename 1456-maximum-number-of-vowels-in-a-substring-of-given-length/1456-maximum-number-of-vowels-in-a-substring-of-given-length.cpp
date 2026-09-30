class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n=s.size();
        int low=0;
        int high=0;
        int current_vowels = 0;
        int max_num=0;
        while(high<n){
            if(vowels.count(s[high])){
                current_vowels++;
            }
            if (high - low + 1 > k) {
                if (vowels.count(s[low])) {
                    current_vowels--;
                }
                low++;
            }
            max_num = max(max_num, current_vowels);
            high++;
        }return max_num;
    }
};