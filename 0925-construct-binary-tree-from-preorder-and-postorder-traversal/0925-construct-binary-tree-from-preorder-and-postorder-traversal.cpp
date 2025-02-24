/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
        int n = preorder.size();
        vector<int> indsPre(n + 1), indsPost(n + 1);
        for(int i = 0; i < n; ++i)
            indsPre[preorder[i]] = i,
            indsPost[postorder[i]] = i;
        
        auto solve = [&](int lpre, int rpre, int lpost, int rpost, auto &solve) -> TreeNode * {
            if(lpre < 0
            || lpre >= n
            || lpost < 0
            || rpost >= n)
                return nullptr;

            if(lpre == rpre)
                return new TreeNode(preorder[lpre]);
            
            int left = preorder[lpre + 1],
                right = postorder[rpost - 1];
            
            if(left == right)
                return new TreeNode(
                    preorder[lpre],
                    solve(lpre + 1, rpre, lpost, rpost - 1, solve),
                    nullptr
                );
            
            return new TreeNode(
                preorder[lpre],
                solve(lpre + 1, indsPre[right] - 1, lpost, indsPost[left], solve),
                solve(indsPre[right], rpre, indsPost[left] + 1, rpost - 1, solve)
            );
        };

        return solve(0, n - 1, 0, n - 1, solve);
    }
};