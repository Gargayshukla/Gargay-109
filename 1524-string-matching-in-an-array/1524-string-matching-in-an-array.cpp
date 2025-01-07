class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        
        unordered_set<string> set;

        vector<string> ans = {};

        for(int i=0; i<words.size(); i++)
        {
            for(int j=0; j<words.size(); j++)
            {
  if(i !=j && words[i].size() < words[j].size() && words[j].contains(words[i]))
                set.insert(words[i]);
            }
        
        }
    

    for(auto i : set)
    {
        ans.push_back(i);
    }

    return ans;
    }
};