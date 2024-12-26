class Solution {
public:
    int solve(vector<int>& nums, int target,int i,int currsum,unordered_map<string,int>&mp){
        if(i==nums.size()){
            if(currsum==target){
                return 1;
            }
            else{
            return 0;
        }
        }
        string key=to_string(i)+"_"+to_string(currsum);
        if(mp.count(key)){
              return mp[key];
        }
        int plus=solve(nums,target,i+1,currsum+nums[i],mp);
        int minus=solve(nums,target,i+1,currsum-nums[i],mp);
        return mp[key]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int>mp;
        return solve(nums,target,0,0,mp);
    }
};