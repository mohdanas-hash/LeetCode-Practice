class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0;
        int alt=0;
        for(int val: gain){
            alt+=val;
            sum=max(sum,alt);
        }return sum;
    }
};