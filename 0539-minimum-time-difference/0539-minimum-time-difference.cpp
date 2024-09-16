class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        int n = timePoints.size();
        vector<int> time;
        int ans = INT_MAX;

        for(int i=0; i<n; i++)
        {
            int hr = stoi(timePoints[i].substr(0,2));

            int min = stoi(timePoints[i].substr(3,2));
            int total = hr*60 + min;
            time.push_back(total);
        }
       
       sort(time.begin(),time.end());

       for(int i=0; i<n-1; i++)
       {
        ans = min(ans, abs(time[i] - time[i+1]));
       }

        return min(ans, 1440-(time.back() - time[0]));
    }
};