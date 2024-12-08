class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<vector<int>> answer;
        for (auto& event : events) {
            int start = event[0];
            int end = event[1];
            int val = event[2];
            answer.push_back({start, 1, val});
            answer.push_back({end + 1, -1, val});
        }
        sort(answer.begin(), answer.end());
        int max_value = 0;
        int max_seen = 0;

        for (auto event : answer) {
            int point = event[0];
            int status = event[1];
            int anything = event[2];
            if (status == 1) {
                max_value = max(max_value, max_seen + anything);
            } else {
                max_seen = max(max_seen, anything);
            }
        }

        return max_value;
    }
};