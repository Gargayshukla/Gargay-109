class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        long long ans = 0;

        priority_queue<int> score;

        for(auto i:nums)
        {
            score.push(i);     //we push the score 
        }

        while(k--)
        {
            int res = score.top();
            score.pop();
            ans += res;
            score.push(ceil((double) res/3));
        }
    
     return ans;
    }
};