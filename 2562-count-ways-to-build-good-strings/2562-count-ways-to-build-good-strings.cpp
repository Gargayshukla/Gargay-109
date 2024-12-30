class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        
        const int n  = 1e9 + 7;
        int dp[100001] = {0};
        dp[0] = 1;

        for(int i=1; i<=high; i++)
        {
            long long a = 1;
            if(i>=zero)a+=dp[i-zero];
            if(i>=one)a+=dp[i-one];
            dp[i]=a%n;

        }

        return (dp[high]-dp[low-1]+n)%n;
    }
};