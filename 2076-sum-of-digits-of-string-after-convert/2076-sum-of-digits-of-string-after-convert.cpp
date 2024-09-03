class Solution {
public:
    int getLucky(string s, int k) {
        
        string ans = "";

        //Approach - 

        // convert string character to number
        // while iterate till k-- 
        // calcute sum of digits in string
        //convert the character string to integer and add to curr sum
        //update the ans after each iteration
        // return the final ans after converting final string to integer

        for(auto i : s)
        {
            int num = i - 'a' + 1;
            ans = ans + to_string(num);
        }

        while(k--)
        {
            int sum = 0;

            for(auto i : ans)
            {
                sum = sum + i - '0';
            }
             ans = to_string(sum);
        }

        return stoi(ans);
    }
};