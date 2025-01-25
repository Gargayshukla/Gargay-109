class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        map<int,queue<int>> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push(i);
        }
        sort(nums.begin(),nums.end());
        vector<int> ans(n);
        int start=0;
        // can also use set as temp can only be used after sorting it
        vector<int> temp;
        int i;
        for( i=0;i<n;i++){
            if(i!=0 && nums[i]>(nums[i-1]+ limit)){
                sort(temp.begin(),temp.end());
                for(int j=0;j<i-start;j++){
                    ans[temp[j]]=nums[j+start];
                }
                temp={};
                start =i;
            }
            temp.push_back(mp[nums[i]].front());
            mp[nums[i]].pop();
        }
         if(temp.size()){
            sort(temp.begin(),temp.end());
            for(int j=0;j<i-start;j++){
                ans[temp[j]]=nums[j+start];
            }
        }
        return ans;
    }
};