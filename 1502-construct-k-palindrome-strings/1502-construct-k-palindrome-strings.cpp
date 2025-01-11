class Solution {
public:
    bool canConstruct(string s, int k) {
        
        if(s.size() < k)
        {
            return false;
        }

        int count = 0;
        vector<int> freq(26, 0);

        for(char c : s)
        freq[c - 'a']++;

        for(int f : freq)
        {
            if(f % 2)
            {
                count++;
            }
        }

        return count <= k;
    }
};