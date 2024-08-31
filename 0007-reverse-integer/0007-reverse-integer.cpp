class Solution {
public:
        int reverse(int x) {
        
        long long ans = 0;

        while(x!=0)
        {
             int num = x % 10;

             if((ans > INT_MAX/10 )|| (ans < INT_MIN/10)){
             
                return 0;
             }
             ans = (ans * 10) + num;
             x = x/10;
        }
        return ans;
    }
};