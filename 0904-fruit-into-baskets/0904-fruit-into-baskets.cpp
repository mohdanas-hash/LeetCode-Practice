class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int ,int> mp;
        int low=0,high=0;
        int n=fruits.size();
        int mx_fruits=0;
        
        for(int high=0; high<n; high++){
            mp[fruits[high]]++;

            while(mp.size()>2){
                mp[fruits[low]]--;
                if(mp[fruits[low]]==0) mp.erase(fruits[low]);
                low++;
            }

            mx_fruits=max(mx_fruits,high-low+1);
            // high++;
        }
        return mx_fruits;
    }
};