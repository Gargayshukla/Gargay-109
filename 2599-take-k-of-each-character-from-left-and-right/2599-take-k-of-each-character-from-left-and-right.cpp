class Solution {
public:
    int takeCharacters(string s, int k) {
        
        vector<int> ans(3,0);

        for(char c: s)
        {
            ans[c-'a']++;
        }

        if(ans[0] < k || ans[1] < k || ans[2] < k)
        {
            return -1;
        }

        int l = 0;
        int r = 0;

        int a = 0;

        while(r < s.size())
        {
            ans[s[r]-'a']--;
        
        while(l<=r & (ans[0]<k || ans[1] <k || ans[2] < k))
        {
            ans[s[l]-'a']++;
            l++;
        }

        a = max(a, r-l+1);
        r++;

    }

    return s.size() - a;
    }
};