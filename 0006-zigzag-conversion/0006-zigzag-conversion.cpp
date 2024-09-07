class Solution {
public:
    string convert(string s, int numRows) {
        
        vector<string>ans(numRows);

        if(numRows == 1)
        {
            return s;
        }

        bool flag = false;
        int i=0;

        for(auto ch : s)
        {
            ans[i] = ans[i] + ch;

        if(i == 0 || i==numRows - 1)
        {
            flag = !flag;
        }

        if(flag)
        {
            i = i+1;
        }
        else
        {
            i = i-1;
        }
        }
       string conv ="";

       for(auto str: ans)
       {
        conv = conv + str;
       }

       return conv;
    }
};