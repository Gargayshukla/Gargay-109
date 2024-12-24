class Solution {
public:
    int bfs(int s,vector<vector<int>> adj,int n){
        vector<int> visited(n);
        vector<int> depth(n);
        queue<int> q;
        q.push(s);
        visited[s]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto child:adj[node]){
                if(visited[child])continue;
                depth[child]=1+depth[node];
                q.push(child);
                visited[child]=1;
            }
        }
        return *max_element(depth.begin(),depth.end());
    }
    int bfs2(int s,vector<vector<int>> adj,int n){
        vector<int> visited(n);
        vector<int> depth(n);
        queue<int> q;
        q.push(s);
        visited[s]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto child:adj[node]){
                if(visited[child])continue;
                depth[child]=1+depth[node];
                q.push(child);
                visited[child]=1;
            }
        }
        int val= *max_element(depth.begin(),depth.end());
        for(int i=0;i<depth.size();i++){
            if(depth[i]==val){
                return i;
            }
        }
        return 0;
    }
    int calculate_diameter(vector<vector<int>> adj,int n){
        int start=bfs2(0,adj,n);
        return bfs(start,adj,n);

    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1,m=edges2.size()+1;
        vector<vector<int>> adj1(n),adj2(m);
        for(auto i:edges1){
            int x=i[0],y=i[1];
            adj1[x].push_back(y);
            adj1[y].push_back(x);
        }for(auto i:edges2){
            int x=i[0],y=i[1];
            adj2[x].push_back(y);
            adj2[y].push_back(x);
        }

        int d1=calculate_diameter(adj1,n);
        int d2=calculate_diameter(adj2,m);
        return max(d2,max(d1,(d1+1)/2+(d2+1)/2+1));
    }
};