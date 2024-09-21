class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        if(strs.empty())
        {
            return "";
        }

        string ans = strs[0];

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<ans.size(); j++)
            {
                if(ans[j] != strs[i][j])
                {
                    ans.resize(j);
                }
            }
        }

        return ans;
    }
};