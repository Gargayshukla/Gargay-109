class Solution {
public:
    bool possible(int mid, int n, vector<int>& quantities)
    {
        for(int q : quantities)
        {
            n-=(q+mid-1)/mid;
            
                if(n<0)
                {
                    return false;
                }
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        int n1 = quantities.size();

        int s = 1;
        int e =  *max_element(quantities.begin(), quantities.end());

        int ans = 0;

        while(s<=e)
        {
            int mid  = s+(e-s)/2;

            if(possible(mid, n, quantities))
            {
                ans = mid;
                e = mid-1;
            }
            else
            
                s = mid+1;
        
        }
        
        return ans;
    }
};