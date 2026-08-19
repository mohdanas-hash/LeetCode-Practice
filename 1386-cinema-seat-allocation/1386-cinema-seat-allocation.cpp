#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxNumberOfFamilies(int n, std::vector<std::vector<int>>& reservedSeats) {
        std::unordered_map<int, int> reserved;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                reserved[row] |= (1 << (col - 2));
            }
        }
        
        int maxGroups = n * 2;
        
        int leftMask   = 0b00001111;
        int rightMask  = 0b11110000;
        int middleMask = 0b00111100;
        
        for (const auto& [row, mask] : reserved) {
            bool leftPossible   = (mask & leftMask) == 0;
            bool rightPossible  = (mask & rightMask) == 0;
            bool middlePossible = (mask & middleMask) == 0;
            
            if (leftPossible && rightPossible) {
                continue;
            } else if (leftPossible || rightPossible || middlePossible) {
                maxGroups -= 1;
            } else {
                maxGroups -= 2;
            }
        }
        
        return maxGroups;
    }
};