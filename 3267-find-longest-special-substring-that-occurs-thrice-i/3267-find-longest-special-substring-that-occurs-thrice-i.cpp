class Solution {
public:
    int maximumLength(string s) {
        
        int ans = -1;

        for(char ch = 'a'; ch <= 'z'; ch++)
        {
            string temp = "";
            for(int i = 0; i<50; i++)
            {
                int count = 0;
                temp += ch;

                for(int j = 0; j<s.length(); j++)
                {
                    if(s[j] == ch)
                    {
                        if(s.substr(j, temp.length()) == temp)
                        {
                            count++;
                        }

                        if(count >= 3)
                        {
                            int t  = temp.length();
                            ans = max(ans, t);
                            continue;
                        }
                    }
                }
            }
        }

        return ans;
    }
};