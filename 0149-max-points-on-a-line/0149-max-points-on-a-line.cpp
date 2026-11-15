#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int maxPoints(std::vector<std::vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int max_points = 1;

        for (int i = 0; i < n; ++i) {
            std::unordered_map<long long, int> slope_map;
            int duplicates = 1;
            int local_max = 0;

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicates++;
                    continue;
                }

                // Reduce the fraction using GCD
                int gcd_val = std::gcd(dx, dy);
                dx /= gcd_val;
                dy /= gcd_val;

                // Ensure consistent sign representation for slopes
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                // Pack dx and dy into a single 64-bit key for the hash map
                long long key = ((long long)dx << 32) | (unsigned int)dy;

                slope_map[key]++;
                local_max = std::max(local_max, slope_map[key]);
            }

            max_points = std::max(max_points, local_max + duplicates);
        }

        return max_points;
    }
};