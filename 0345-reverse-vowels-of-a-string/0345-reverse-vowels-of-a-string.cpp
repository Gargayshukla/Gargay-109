class Solution {
public:
    bool vowels(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    string reverseVowels(string s) {
        
        int i = 0;
        int j = s.size() - 1;

        while(i<j)
        {
        if(vowels(s[i]) && vowels(s[j]))
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }

        else if(!vowels(s[i]))
        {
            i++;
        }

        else if(!vowels(s[j]))
        {
            j--;
        }
        }

        return s;
    }
};