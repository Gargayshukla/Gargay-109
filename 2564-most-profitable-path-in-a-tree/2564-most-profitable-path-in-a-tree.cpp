class Solution {
    int n;
    void bfs(int &bob, vector<int> &vis, vector<int> g[]){
        vector<int> par(n, -1);
        queue<int> q;
        q.push(bob);
        vis[bob] = 0;

        while (!q.empty()){
            auto node = q.front(); q.pop();
            if(node == 0) break;
            for(auto &nbr: g[node]){
                if(vis[nbr] == -1){
                    vis[nbr] = vis[node] + 1;
                    par[nbr] = node;
                    q.push(nbr);
                }
            }
        }

        int src = 0;
        unordered_set<int> st;
        while (src != bob){
            st.insert(src);
            src = par[src];
        }
        st.insert(bob);

        for(int i = 0; i < n; i++) 
            if(vis[i] != -1 && !st.count(i)) vis[i] = -1;
    }
    public:
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            n = amount.size();
            vector<int> vis(n, -1);
            vector<int> g[n];
            for(auto &it: edges){
                g[it[0]].push_back(it[1]);
                g[it[1]].push_back(it[0]);
            }
            bfs(bob, vis, g);
            
            int maxProfit = INT_MIN;
            queue<pair<int, pair<int, int>>> q1;
            
            if(vis[0] == 0) q1.push({0, {0, amount[0]/2}});
            else q1.push({0, {0, amount[0]}});
            vis[0] = -2;
    
            while (!q1.empty()){
                auto [src, calVal] = q1.front(); q1.pop();
                auto [dis, currProfit] = calVal;
    
                if(g[src].size() == 1 && src != 0) maxProfit = max(maxProfit, currProfit);
    
                for(auto &nbr: g[src]){
                    if(vis[nbr] != -2){
                        int newProfit = currProfit;
                        if(vis[nbr] == dis+1) newProfit += amount[nbr]/2;
                        else if((vis[nbr] > dis + 1) || vis[nbr] == -1) newProfit += amount[nbr];
                        vis[nbr] = -2;
                        q1.push({nbr, {dis+1, newProfit}});
                    }
                }
            }
            return maxProfit;
        }
    };