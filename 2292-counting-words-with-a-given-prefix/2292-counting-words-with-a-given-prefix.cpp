class Solution {
public:
    bool isPrefixWord(const string& word,const string& pr) {
        int start = 0;
        int prefsize = pr.size();
       
        while (start != prefsize) {
            if (word[start] != pr[start]) {
                return false;
            }
            start++;
        }

        return true;
    }

    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;

        for (const string& word : words) {

            if (word[0] != pref[0])
                continue;

            if (isPrefixWord(word, pref))
                ans++;
        }

        return ans;
    }
};