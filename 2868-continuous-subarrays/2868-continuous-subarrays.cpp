class Solution {
public:
typedef long long ll;
    long long continuousSubarrays(vector<int>& nums) {
       int i=0,j=0;
       ll cnt=0,n=nums.size();
       map<int, int>mp;
        while(j<n){
            mp[nums[j]]++;
            while(mp.rbegin()->first - mp.begin()->first>2){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;

            }
            cnt+=j-i+1;
            j++;
        }
    return cnt;
    }
};