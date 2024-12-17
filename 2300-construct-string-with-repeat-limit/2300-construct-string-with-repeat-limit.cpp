class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        vector<int> alpha(26, 0);
        for (auto i : s) {
            alpha[i - 'a']++;
        }
        
        string ans;
        int prev=25;  
        for (int i = 25; i >= 0; ) {
            if (alpha[i] == 0) {
                i--;
                continue;
            }
            if(alpha[i]<=limit){
                ans+=string(alpha[i],i+'a');
                alpha[i]=0;
                i--;
            }else{
                ans+=string(limit,i+'a');
                alpha[i]-=limit;
                prev=i-1;
                while(prev>=0 and alpha[prev]==0) prev--;
                if(prev>=0){
                    ans+=('a'+prev);
                    alpha[prev]--;
                }
                else break;
            }
        }      
        return ans;
    }
};