class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        
        int n = arr.size();

        int s = 0;

        while(s+1 < n && arr[s] <= arr[s+1])
        {
            s++;
        }

        if(s == n-1)
        {
            return 0;
        }

        int e = n-1;
        while(e > 0 && arr[e-1] <= arr[e])
        {
            e--;
        }

        int ans = min(n-s-1, e);

        int i = 0; 
        int j = e;

        while(i<=s && j<n)
        {
            if(arr[i] <= arr[j]){
            ans = min(ans, j - i -1);
            i++;
        }
        else
        {
            j++;
        }
        }

        return ans;
    }
};