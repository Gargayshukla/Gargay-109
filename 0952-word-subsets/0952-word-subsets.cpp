class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        int n = words2.size();
        vector<int> v(26, 0);
        for(int i=0 ; i<n ; i++){
            vector<int> freq(26, 0);
            for(char ch:words2[i]){
                freq[ch-'a']++;
            }
            for(int i=0 ; i<26 ; i++) v[i] = max(v[i], freq[i]);
        }
        for(auto str : words1){
            bool flag = true;
            vector<int> check(26, 0); // in words1 check if universal ya nhi 
            for(char ch: str){
                check[ch-'a']++;
            }
            for(int i=0 ; i<26 ; i++){
                if(check[i]<v[i]){
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(str);
        }
        return ans;
    }
};