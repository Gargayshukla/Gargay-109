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
    private:
    void solve(int lvl, TreeNode*& ptr1, TreeNode*& ptr2){
        if(ptr1 == NULL || ptr2 == NULL) return;

        if(lvl % 2 == 1){
            swap(ptr1 -> val, ptr2 -> val);
        }

        solve(lvl+1,ptr1 -> left,ptr2 -> right);
        if(ptr1 != ptr2) solve(lvl+1,ptr1 -> right,ptr2 -> left);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        solve(0,root,root);
        return root;
    }
};