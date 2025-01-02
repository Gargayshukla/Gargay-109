class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix_sum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            char start = words[i][0];
            char end = words[i].back();
            prefix_sum[i + 1] = prefix_sum[i] + (isVowel(start) && isVowel(end));
        }

        vector<int> res;
        res.reserve(queries.size());
        for (const auto& query : queries) {
            res.push_back(prefix_sum[query[1] + 1] - prefix_sum[query[0]]);
        }
        return res;
    }
};