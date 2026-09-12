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
    int res=0;
    int diameterOfBinaryTree(TreeNode* root) {
        int r = aux(root);
        return res;
    }

    int aux(TreeNode* root){
        //if root is null or single node without any child
        if(!root) return 0;
        //if(!root->left && !root->right) return 1;

        int l = aux(root->left);
        int r = aux(root->right);

        res = max(res, l+r);

        return 1+max(l, r);
    }
};
