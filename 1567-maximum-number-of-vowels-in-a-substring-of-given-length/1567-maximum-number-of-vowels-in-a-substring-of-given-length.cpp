class Solution {
public:
    bool vowel(char &ch)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int maxVowels(string s, int k) {
        
        int n = s.size();
        int i = 0;
        int j = 0;

        int count = 0;
        int maxi = INT_MIN;

        while(j<n)
        {
            if(vowel(s[j]))
            {
            count++;
            }

            if(j - i + 1 ==k )
            {
                maxi = max(maxi,count);

                
                if(vowel(s[i]))
                {
                    count--;
                }
                i++;              
            }
            
            j++;
        }

        return maxi;
    }
};