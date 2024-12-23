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
    int minimumOperations(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans=0;
     queue<TreeNode*>q;
     q.push(root); 
     while(!q.empty()){
        int size=q.size();
         vector<int>v;  
        for(int i=0;i<size;i++){
            TreeNode*front=q.front();
            q.pop();
            v.push_back(front->val);
            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
        }
     int n=v.size();
     vector<pair<int,int>>temp(n);
     for(int i=0;i<n;i++){
        temp[i]={v[i],i};
     }
     sort(temp.begin(),temp.end());
     for(int i=0;i<n;i++){
        while(temp[i].second!=i){ 
            ans++;
            swap(temp[i],temp[temp[i].second]);
        }
     }
     }
     return ans;
    }
};