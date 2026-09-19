class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> mp(256,0);

        int n=s.size();
        int low=0;
        int max_freq=0;
        int max_len=0;

        for(int high=0; high<n; high++){
            mp[s[high]]++;
            
            max_freq=max(max_freq, mp[s[high]]);

            while((high - low + 1) - max_freq  >  k ){
                mp[s[low]]--;
                low++;
            }

            max_len=max(max_len, high-low+1);
        }

        return max_len;
    }
};