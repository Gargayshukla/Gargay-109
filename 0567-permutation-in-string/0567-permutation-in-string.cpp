class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n1 = s1.size();
        int n2 = s2.size();

        if(s2.size() < s1.size())
        {
            return false;
        }

        vector<char> st1(26,0);
        vector<char> st2(26,0);

        for(int i=0; i<n1; i++)
        {
            st1[s1[i] - 'a']++;

            st2[s2[i] - 'a']++;
        }

        if(st1 == st2)
        {
            return true;
        }

        int j = 0;
        for(int i = n1; i<n2; i++)
        {
            st2[s2[j] - 'a']--;
            st2[s2[i] - 'a']++;

            if(st1 == st2)
            {
                return true;
            }
            j++;
        }

        return false;

    }
};