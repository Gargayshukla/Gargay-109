class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        map<string, int> mp;

        vector<string> ans;
        stringstream st(s1 + " " + s2);

        string res;

        while(st >> res)
        {
            mp[res]++;
        }

        for(auto str:mp)
        {
            if(str.second == 1)
            {
                ans.push_back(str.first);
            }
        }

        return ans;
    }
};