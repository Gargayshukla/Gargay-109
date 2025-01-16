class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size()%2;
        int m=nums2.size()%2;
        int ans=0;
        if(n==0 & m==0) return 0;
        else if(n!=0 && m==0){
            for(auto it: nums2){
                ans^=it;
            }
        }
        else if(n==0 && m!=0){
            for(auto it: nums1){
                ans^=it;
            }
        }
        else{
            int n1=0;
            for(auto it: nums2){
                n1^=it;
            }
            for(auto it: nums1){
                n1^=it;
            }
            ans=n1;
        }
        return ans;
    }
};