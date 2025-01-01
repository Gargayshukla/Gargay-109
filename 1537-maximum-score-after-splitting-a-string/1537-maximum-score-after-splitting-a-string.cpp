class Solution {
public:
    int maxScore(string s) {
        
        int n = s.size();

        int l = 0, e = 0;
        int ans = INT_MIN;

        for(int i=0; i<=n-2; i++)
        {
            if(s[i] == '1')
            {
                e++;
            }
            else
            {
                l++;
            }
            
            ans = max(ans, l-e);
        }

        if(s[n-1] == '1')
        {
            e++;
        }

        return ans+e;
    }
};