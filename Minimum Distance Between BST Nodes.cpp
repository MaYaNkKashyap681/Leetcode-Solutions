class Solution {
    void helper(TreeNode *root, vector<int> &nodes)
    {
        if(root == NULL) {return;}
        nodes.push_back(root->val);
        helper(root->left, nodes);
        helper(root->right, nodes);
    }
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> nodes;
        helper(root, nodes);

        int ans = INT_MAX;

        for(int i = 0; i < nodes.size(); ++i) {
            for(int j = i + 1; j < nodes.size(); ++j) {
                ans = min(abs(nodes[i] - nodes[j]), ans);
            }
        }
        return ans;
    }
};
