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
int depth(TreeNode* root,int mini)
{

     int left = INT_MAX;
    int right = INT_MAX;

    if(root->left != NULL) left = 1+depth(root->left,mini);

    if(root->right != NULL)right= 1+depth(root->right,mini);


    if(left == INT_MAX    && right == INT_MAX) return 1;

    return min(left,right);
    



    

}
    int minDepth(TreeNode* root) {

        if(root == NULL) return 0;

        int mini = INT_MAX;
       int left;
       int right;

        int ans = depth(root,mini);
        return ans;
        
    }
};
