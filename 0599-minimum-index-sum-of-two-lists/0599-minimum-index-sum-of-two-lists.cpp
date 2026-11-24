#include <vector>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> indexMap;
        indexMap.reserve(list1.size());
        for (int i = 0; i < static_cast<int>(list1.size()); ++i) {
            indexMap[list1[i]] = i;
        }

        vector<string> result;
        int minSum = INT_MAX;

        for (int j = 0; j < static_cast<int>(list2.size()); ++j) {
            auto it = indexMap.find(list2[j]);
            if (it != indexMap.end()) {
                int sum = it->second + j;
                if (sum < minSum) {
                    minSum = sum;
                    result.clear();
                    result.push_back(list2[j]);
                } else if (sum == minSum) {
                    result.push_back(list2[j]);
                }
            }
        }

        return result;
    }
};