class Solution {
public:
    int getLucky(string s, int k) {
        
        int n = s.size();

        long long sum = 0;

        for(int i=0; i<n; i++)
        {
        int num = s[i] - 'a' + 1;
        while(num>0)
        {
            sum = sum + num%10;
            num = num/10;
        }
        }
       
        while(k>1)
        {
            long long newsum = 0;
            while(sum>0)
            {
                newsum = newsum + sum %10;
                sum = sum/10;
            }
            sum = newsum;
            k--;
        }

        return sum;
    }
};