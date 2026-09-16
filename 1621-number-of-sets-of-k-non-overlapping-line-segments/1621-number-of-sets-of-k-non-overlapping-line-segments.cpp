class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;
        long long N = n + k - 1;
        long long K = 2 * k;

        if (K > N) return 0;

        auto power = [&](long long base, long long exp) {
            long long res = 1;
            base %= MOD;
            while (exp > 0) {
                if (exp % 2 == 1) res = (res * base) % MOD;
                base = (base * base) % MOD;
                exp /= 2;
            }
            return res;
        };

        auto modInverse = [&](long long num) {
            return power(num, MOD - 2);
        };

        long long num = 1, den = 1;
        for (int i = 0; i < K; i++) {
            num = (num * (N - i)) % MOD;
            den = (den * (i + 1)) % MOD;
        }

        return (num * modInverse(den)) % MOD;
    }
};