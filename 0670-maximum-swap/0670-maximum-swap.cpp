class Solution {
public:
    int maximumSwap(int num) {
        
        vector<int> ans;

        int swap = num;

        while(swap)
        {
            int temp = swap%10;
            ans.push_back(temp);
            swap = swap/10;
        }

        int n = ans.size();

        reverse(ans.begin(), ans.end());
        vector<int> sorted = ans;
        sort(sorted.begin(), sorted.end(), greater<int>());

        for(int i=0; i<ans.size(); i++)
        {
            if(ans[i] != sorted[i])
            {
                int swap = ans[i];
                ans[i] = sorted[i];
                int res = sorted[i];

                int index = i+1;

                for(int j=i+1; j<n; j++)
                {
                    if(ans[j] == res)
                    {
                        index = j;
                    }

                }
                ans[index] = swap;
                break;
            }
        }
        int max = 0;

        for(int i=0; i<n; i++)
        {
            max = max*10 + ans[i];
        }

        return max;
    }
};