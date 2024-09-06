class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int n = s.size();

        int ans = 0;
        for(int i = n-1; i>=0; i--)
        {
            if(s[i] != ' ')
            {
                ans = ans + 1;
            }
            else if(ans != 0 && s[i] == ' ')
            {
                break;
            }
        }

        return ans;
    }
};