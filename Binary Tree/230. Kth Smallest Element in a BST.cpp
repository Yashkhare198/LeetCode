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
    void inOrder(TreeNode* root,vector<int>&ans, int k)
    {
        if(root == NULL) return;

         inOrder(root->left,ans,k);

         ans.push_back(root->val);

        //  if(ans.size() == k) return ans[ans.size()-1];

         inOrder(root->right,ans,k);
          
    }
    int kthSmallest(TreeNode* root, int k) {

        vector<int>inorder;

         inOrder(root,inorder,k);

         return inorder[k-1];
        
    }
};
