class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        int n = boxes.size();
        vector<int> left(n,0), right(n,0);

        for (int i = 1, count = 0; i < n; i++) {
            if (boxes[i - 1] == '1') {
                count++;
            }
            left[i] = left[i - 1] + count;
        }
        for (int i = n - 2, count = 0; i >= 0; i--) {
            if (boxes[i + 1] == '1') {
                count++;
            }
            right[i] = right[i + 1] + count;
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = left[i] + right[i];
        }
        return ans;
    }
};