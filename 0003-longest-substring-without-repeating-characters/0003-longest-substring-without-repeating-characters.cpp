class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        set<char> set;
        int n = s.size();
        int st = 0;
        int end = 0;
        int max = 0;

        while(st<n)
        {
            auto it = set.find(s[st]);

        if(it == set.end()){
            if(st - end + 1 > max)
            
            max = st-end+1;
            set.insert(s[st]);
            st++;
            
        }
        
        else
        {
            set.erase(s[end]);
            end++;
        }
        }
        return max;
    }
};