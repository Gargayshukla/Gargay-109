class Solution {
public:
    int calculateDigitSum(int n){
      int ans=0;  
      while(n){
        ans=ans+n%10;
        n=n/10;
      }
      return ans;
    }
    int maximumSum(vector<int>& nums) {
        int ans =-1 ,n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            int digits=calculateDigitSum(nums[i]);
            mp[digits].push_back(nums[i]); 
        }
     
      
        for(auto &it:mp){
             priority_queue<int>q;
           for(auto &nd : it.second){
             q.push(nd);
           }
           int sum=0;
           sum+=q.top();
           q.pop();
           if(q.empty()){
            sum=0;
            continue;
           }
           sum+=q.top();
           q.pop();
           ans=max(ans,sum);
        }
        return ans;
    }
};