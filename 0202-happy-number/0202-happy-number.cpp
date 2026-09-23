class Solution {
public:
    int fun(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            sum += d * d;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = fun(n);
        
        while (fast != 1 && slow != fast) {
            slow = fun(slow);
            fast = fun(fun(fast));
        }
        
        return fast == true;
    }
};