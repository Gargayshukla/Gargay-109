class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int round = 0;

        for(int i=1; i<n; i++)
        {
            if(arr[0] > arr[i])
            {
                round++;
            }
            else
            {
               swap(arr[0],arr[i]);
               round = 1;
            }

            if(round == k)
            {
               return arr[0];
            }
            
        }

        return arr[0];
    }
};