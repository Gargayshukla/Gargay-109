#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor;  // Maps a ball to its color
        unordered_set<int> distinctColors;  // Stores distinct colors
        vector<int> result;

        for (const auto& query : queries) {
            int ball = query[0], color = query[1];

            // If the ball was already colored, remove the previous color if needed
            if (ballColor.count(ball)) {
                int prevColor = ballColor[ball];
                if (prevColor != color) {
                    // Check if the previous color still exists in another ball
                    bool colorStillExists = false;
                    for (const auto& pair : ballColor) {
                        if (pair.second == prevColor && pair.first != ball) {
                            colorStillExists = true;
                            break;
                        }
                    }
                    if (!colorStillExists) {
                        distinctColors.erase(prevColor);
                    }
                }
            }

            // Assign the new color
            ballColor[ball] = color;
            distinctColors.insert(color);

            // Store the count of distinct colors
            result.push_back(distinctColors.size());
        }

        return result;
    }
};