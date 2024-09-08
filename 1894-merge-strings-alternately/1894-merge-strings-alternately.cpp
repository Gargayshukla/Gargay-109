class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int n1 = word1.size();
        int n2 = word2.size();

        string ans = "";
        int i = 0;
        int j = 0;

        while(i<n1 && j<n2)
        {
            ans.push_back(word1[i]);
            ans.push_back(word2[j]);
            i++;
            j++;
        }

        for(; i<n1; i++)
        {
            ans.push_back(word1[i]);
        }

        for(;j<n2; j++)
        {
            ans.push_back(word2[j]);
        }

        return ans;
    }
};