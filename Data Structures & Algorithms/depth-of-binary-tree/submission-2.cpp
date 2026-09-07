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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        stack<pair<TreeNode*, int>> s;
        s.push({root, 1});
        int mxDpth = 1;
        while(!s.empty()){
            TreeNode* nd = s.top().first;
            int d = s.top().second;
            s.pop();
            mxDpth = max(mxDpth, d);
            if(nd->left) s.push({nd->left, d+1});
            if(nd->right) s.push({nd->right, d+1});
        }
        return mxDpth;
    }
};
