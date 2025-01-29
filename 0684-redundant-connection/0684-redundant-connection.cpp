class Solution {
public:
    struct UnionFind {
        int numSets = 0;
        int setSize[1005];
        int parent[1005];
        int rank[1005];

        UnionFind(int n) {
            numSets = n;
            for (int i = 0; i < n; i++) parent[i] = i, setSize[i] = rank[i] = 0;
        }

        void make_set(int i) {
            parent[i] = i;
            rank[i] = 0;
        }

        int find_set(int i) {
            if (i != parent[i])
                parent[i] = find_set(parent[i]);
            return parent[i];
        }

        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) {
                numSets--;
                int x = find_set(i), y = find_set(j);

                if (rank[x] > rank[y]) {
                    parent[y] = x;
                    setSize[x] += setSize[y];
                } else {
                    parent[x] = y;
                    setSize[y] += setSize[x];

                    if (rank[x] == rank[y])
                        rank[y]++;
                }
            }
        }

        bool isSameSet(int i, int j) { return find_set(i) == find_set(j); }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = (int) edges.size();
        UnionFind dsu(n);

        for (int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (dsu.isSameSet(u, v)) {
                return {u, v};
            }

            dsu.unionSet(u, v);
        }

        return {};
    }
};