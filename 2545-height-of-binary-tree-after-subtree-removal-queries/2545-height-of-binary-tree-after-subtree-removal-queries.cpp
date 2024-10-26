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
    map<int,int> lmp,rmp,query;
    void solve(TreeNode* root, int maxi, int depth)
    {
        if(!root)
        {
            return;
        }

        query[root->val] = maxi;
        solve(root->left, max(maxi, depth + rmp[root->val]), depth+1);
        solve(root->right, max(maxi, depth+lmp[root->val]), depth+1);
    }

    int check(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }

        int left = check(root->left);
        int right = check(root->right);
        lmp[root->val] = left;
        rmp[root->val] = right;
        return 1 + max(left,right);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        
       vector<int> ans;
       check(root);

       solve(root->left, rmp[root->val],1);
       solve(root->right,lmp[root->val],1);

       for(auto& i: queries)
       {
        ans.push_back(query[i]);
       }

       return ans;
    }
};