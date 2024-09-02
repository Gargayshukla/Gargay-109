class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
    
      int n  = chalk.size();

      long long sum = 0;

      //Approach - 
      
      // Firstly, sum of all array
      // then divide by k for finding remaining value
      //k < chalk[i] then return i else k = k - chalk[i]

      for(int i=0; i<n; i++)
      {
        sum = sum + chalk[i];      
      }

       k = k % sum;

      for(int i=0; i<n; i++)
      {
        if(k < chalk[i])
        {
            return i;
        }
        k = k - chalk[i];
      }

      return -1;
    }
};