class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        //track the frequency of the numbers
        unordered_map <int,int>mp;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                 mp[nums[i]*nums[j]]++;
            }
        }
        int cnt=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second>=2)cnt+=(it->second)*(it->second-1)/2;
        }
        return cnt*8;
        
    }
};