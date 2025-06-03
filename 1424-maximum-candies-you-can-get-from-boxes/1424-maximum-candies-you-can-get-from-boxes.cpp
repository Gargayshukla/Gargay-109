class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector <int> hasBox(n, 0);
        vector <int> hasKey(n, 0);
        vector <int> visit(n, 0);
        for(int i=0; i<n; ++i)
        {
            if(status[i]==1)
            {
                hasKey[i] = 1;
            }
        }
        deque <int> dq;
        int total = 0;
        for(auto box: initialBoxes)
        {
            hasBox[box] = 1;
            if(hasBox[box]==1 && hasKey[box]==1)
            {
                dq.push_back(box);
                total += candies[box];
                visit[box] = 1;
                //cout << candies[box] << "-" << box << endl;
            }
        }
        while(!dq.empty())
        {
            int i = dq.front();
            dq.pop_front();
            for(auto j: keys[i])
            {
                if(visit[j]!=1)
                {
                    hasKey[j] = 1;
                    if(hasKey[j]==1 && hasBox[j]==1)
                    {
                        dq.push_back(j);
                        total += candies[j];
                        visit[j] = 1;
                        //cout << candies[j] << "-" << j << endl;
                    }
                }
            }
            for(auto j: containedBoxes[i])
            {
                if(visit[j]!=1)
                {
                    hasBox[j] += 1;
                    if(hasKey[j]==1 && hasBox[j]==1)
                    {
                        dq.push_back(j);
                        total += candies[j];
                        visit[j] = 1;
                        //cout << candies[j] << "-" << j << endl;
                    }
                }
            }
        }
        return total;
    }
};