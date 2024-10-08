class Solution {
public:
    int minSwaps(string s) {
        
        int n = s.size();
        int count = 0;
        int ans = 0;

        for(char ch : s)
        {
            if(ch == '[')
            {
                count++;
            }
            else
            {
                count--;
            }
            
            if(count < 0)
            {
                ans++;
                count = 1;
            }
        }

        return ans;
    }
};