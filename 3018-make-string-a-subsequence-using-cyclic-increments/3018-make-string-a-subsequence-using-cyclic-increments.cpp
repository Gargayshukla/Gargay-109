class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        
        int n1 = str1.size();
        int n2 = str2.size();

        int i = 0, j = 0;

        while(i < n1 && j < n2)
        {
            char ch1 = str1[i];
            char ch2 = str2[j];

            if(ch1 == ch2)
            {
                j++;
            }
            else if(ch2 == ch1 + 1 || (ch1 == 'z' && ch2 == 'a'))
            {
                j++;
            }
            i++;
        }

        return j == n2;
    }
};