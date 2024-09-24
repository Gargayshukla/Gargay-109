class Solution {
public:
    int maxPower(string s) {
        
        int n = s.size();
        int count = 1;
        int ans = 1;

        for(int i=1; i<n; i++)
        {
            if(s[i-1] == s[i])
            {
                count++;
            }
            else
            {
                ans = max(ans,count);
                count = 1;
            }
        }

        ans = max(ans,count);
        return ans;
    }
};