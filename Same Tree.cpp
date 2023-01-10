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

    bool solution(TreeNode *p, TreeNode *q) 
    {
        if(p == NULL and q != NULL or p != NULL and q == NULL) {
            return false;
        }
        if(p == NULL and q == NULL) {
            return true;
        }
        else if(p != NULL and q != NULL and p->val != q->val) {
            return false;
        }

        bool a = false;
        bool b = false;
        a = solution(p->left, q->left);
        b = solution(p->right, q->right);
        
        return a and b;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solution(p, q);
    }
};
