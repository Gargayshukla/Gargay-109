class Solution {
public:
    string answerString(string word, int numFriends) {
        
        int n = word.size();

        string ans = "";

        if(numFriends == 1)
        {
            return word;
        }

        int a = n - numFriends + 1;

        for(int i=0; i<n; i++)
        {
            ans = max(ans, word.substr(i, a));
        }

        return ans;
    }
};