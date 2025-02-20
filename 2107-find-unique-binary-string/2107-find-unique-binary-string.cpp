class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans="";

        for(int i=0; i<nums.size(); i++) {
            int ch=nums[i][i]-'0';

            int xor_op = 1^ch;
            ans+=xor_op+'0';
        }

        return ans;
    }
};