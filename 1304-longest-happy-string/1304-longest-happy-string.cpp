class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<pair<int,char>> p;

        string ans = "";

         p.push({a,'a'});
         p.push({b,'b'});
         p.push({c,'c'});

        while(p.size())
        {
            if(p.top().first == 0) break;

            int x = p.top().first, size = ans.size();
            char y = p.top().second;
            p.pop();

            if(size>=2 && ans[size-1] == ans[size-2] && ans[size-1] == y)
            {
                int occ = p.top().first;
                char val = p.top().second;
                p.pop();

                if(occ == 0) break;

                ans = ans + val;
                occ--;
                p.push({occ,val});
            }
            else
            {
                ans = ans+y;
                x--;
            }
             p.push({x,y});
        }


       return ans;
    }
};