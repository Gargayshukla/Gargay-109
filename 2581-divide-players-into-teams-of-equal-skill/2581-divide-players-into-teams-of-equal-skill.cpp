class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        int n = skill.size();

        sort(skill.begin(),skill.end());
        
        int i = 0;
        int j = n-1;
        int sum = skill[i] + skill[j];
        int total = skill[i++] * skill[j--];

        long long ans = 0;
        ans = ans + total;

        while(i<j)
        {
            int res = skill[i] + skill[j];
            if(res != sum)
            {
                return -1;
            }

            total = skill[i++] * skill[j--];
            ans = ans + total;
        }

        return ans;
    }
};