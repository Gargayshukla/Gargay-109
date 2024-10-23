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
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        root-> val = 0;

        q.push(root);

        vector<int> ans;

        ans.push_back(0);

        map<TreeNode*, int> mp;

        while(!q.empty())
        {
            int size = q.size();

            int anssum = 0;

        while(size--)
        {
            auto node = q.front();
            q.pop();

            int sum = 0;

            if(node->left)
            {
                sum += node->left->val;
                q.push(node->left);
            }

            if(node->right)
            {
                sum += node->right->val;
                q.push(node->right);
            }

            anssum += sum;
            mp[node] = sum;
        }

        ans.push_back(anssum);
        }
        q.push(root);

        int i = 1;

        while(!q.empty())
        {
            int size = q.size();
            int anssum = ans[i];

            while(size--)
            {
                auto node = q.front();
                q.pop();

                int sum = mp[node];

               if(node->left) 
               {
                node->left->val = anssum - sum;
                q.push(node->left);
               }

               if(node->right)
               {
                node->right->val = anssum - sum;
                q.push(node->right);
               }
            }
         i++;

        }

        return root;
    }
};