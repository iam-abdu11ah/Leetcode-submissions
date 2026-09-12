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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        int d = l+r;
        int leftDia = diameterOfBinaryTree(root->left);
        int rightDia = diameterOfBinaryTree(root->right);

        return max(max(leftDia, rightDia), d);
    }

    int aux(TreeNode* root, int currDiam){
        //if root is null or single node without any child
        if(!root) return currDiam;

        int l=currDiam;
        if(root->left) l = aux(root->left, currDiam+1);
        int r=currDiam;
        if(root->right) r = aux(root->right, currDiam+1);
   
        int mxD = max(l, r);

        return mxD;

    }

    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int maxDepthLeft = maxDepth(root->left);
        int maxDepthRight = maxDepth(root->right);

        return 1+max(maxDepthLeft, maxDepthRight);
    }
};
