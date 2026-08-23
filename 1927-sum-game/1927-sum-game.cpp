class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                leftQ++;
            } else {
                leftSum += num[i] - '0';
            }
        }

        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                rightQ++;
            } else {
                rightSum += num[i] - '0';
            }
        }

        
        if ((leftQ + rightQ) % 2 != 0) {
            return true;
        }

        
        return (leftSum - rightSum) != (rightQ - leftQ) * 9 / 2;
    }
};