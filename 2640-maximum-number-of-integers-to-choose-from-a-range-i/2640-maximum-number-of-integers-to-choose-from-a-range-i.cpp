class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
        unordered_set<int> bannedset(banned.begin(), banned.end());

        int sum = 0, ans = 0;

        for(int i=1; i<=n; i++)
        {
            if(bannedset.find(i) == bannedset.end() && sum + i <= maxSum)
            {
                sum += i;
                ans++;
            }
        }

      return ans;
    }
};