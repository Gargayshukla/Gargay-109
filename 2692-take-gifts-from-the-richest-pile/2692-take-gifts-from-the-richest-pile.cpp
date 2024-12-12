class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
      priority_queue<int> p;

      for(auto x : gifts)
      p.push(x);

      long long ans = 0;

      int n = gifts.size();

      while(k--)
      {
        int x = p.top();
        p.pop();
        p.push(sqrt(x));
      }

      while(!p.empty())
      {
        ans += p.top();
        p.pop();
      }

       return ans;
    }
};