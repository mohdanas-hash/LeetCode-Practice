class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int currentTank =0;
        int start = 0;
        for(int i =0; i < gas.size();i++){
            int diff = gas[i] - cost[i];

            total += diff;
            currentTank += diff;
            if(currentTank < 0){
                start = i + 1;
                currentTank = 0;
            }
        }


        return (total >= 0) ? start : -1;
    }
};