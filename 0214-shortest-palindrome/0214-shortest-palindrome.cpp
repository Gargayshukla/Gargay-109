class Solution {
public:
    void func(vector<int>& curr, string ans)
    {
        int i=0;
        int j = 1;

        while(j<ans.length())
        {
            if(ans[i] == ans[j])
            {
                i++;
                curr[j] = i;
                j++;
            }
            else
            {
                if(i==0)
                {
                    j++;
                }
                else
                {
                    i=curr[i-1];
                }
            }

        }
    }

    string shortestPalindrome(string s) {
       
       string st = s;
       reverse(st.begin(),st.end());
       string ans = s + '#' + st;

       vector<int> curr(ans.length(),0);

       func(curr,ans);
       int i = curr[ans.length()-1];
       string temp = s.substr(i);

       reverse(temp.begin(),temp.end());
       return temp+s;
    }
};