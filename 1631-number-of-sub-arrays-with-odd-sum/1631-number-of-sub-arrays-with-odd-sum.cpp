class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int m=1e9+7;
        int cnt=0;
        int sum=0;
        int ocnt=0,ecnt=1; 
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum%2==0) {
                cnt=(cnt+ocnt)%m;
                ecnt++;
            } else {
                cnt=(cnt+ecnt)%m;
                ocnt++;
            }
        }
        return cnt;

    }
};