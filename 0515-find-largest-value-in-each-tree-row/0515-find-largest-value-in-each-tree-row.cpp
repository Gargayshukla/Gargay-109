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
    vector<int> largestValues(TreeNode* root) {
        if(!root){
            return {};
        }
        queue<TreeNode*>que;
        que.push(root);
        vector<int>result;
        while(!que.empty()){
            int n=que.size();
            int maxEle=INT_MIN;
            while(n--){
                TreeNode* node=que.front();
                que.pop();
                maxEle=max(maxEle,node->val);
                if(node->left){
                    que.push(node->left);
                }
                if(node->right){
                    que.push(node->right);
                }
            }
            result.push_back(maxEle);
        }
        return result;
    }
};