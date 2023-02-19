class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;

        if(root == NULL) {return ans;}
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) 
        {
            int sz = q.size();

            for(int i = 0; i < sz; ++i) {
                TreeNode* x = q.front();                
                q.pop();
                temp.push_back(x->val);
                if(x->left){q.push(x->left);}
                if(x->right) {q.push(x->right);}
            }

            ans.push_back(temp);
            temp.clear();
        }

        for(int i = 1; i < ans.size(); i+=2) {
            reverse(ans[i].begin(), ans[i].end());
        }

        return ans;
        
    }
};
