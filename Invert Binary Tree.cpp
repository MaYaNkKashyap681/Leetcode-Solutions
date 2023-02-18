class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) {
            return root;
        }
        TreeNode *x = invertTree(root->left);
        TreeNode *y = invertTree(root->right);
        root->left = y;
        root->right = x;
        return root;
    }
};
