class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans = INT_MAX;
        int count = t.size();
        int start = 0;

        map<char, int> mp;

        for(char ch:t)
        {
            mp[ch]++;
        }

        while(j<n)
        {
            if(mp[s[j]] > 0)
            count--;
            mp[s[j]]--;

            while(count ==0)
            {
                int win = j-i+1;
                if(win < ans)
                {
                    ans = win;
                    start = i;
                }
                mp[s[i]]++;

                if(mp[s[i]] > 0)
                    count++;
                    i++;        
            }
            j++;
        }

      return ans == INT_MAX?"":s.substr(start,ans);
    }
};