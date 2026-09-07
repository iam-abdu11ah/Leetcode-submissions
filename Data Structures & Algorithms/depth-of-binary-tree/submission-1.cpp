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


//BFS

class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        if(!root) return 0;
        q.push({root, 1});
        int maxDpth=1;
        while(!q.empty()){
            TreeNode* nd = q.front().first;
            int d = q.front().second;
            q.pop();
            maxDpth = max(maxDpth, d);
            if(nd->left) q.push({nd->left, d+1});
            if(nd->right) q.push({nd->right, d+1});
        }
        return maxDpth;
    }
};
