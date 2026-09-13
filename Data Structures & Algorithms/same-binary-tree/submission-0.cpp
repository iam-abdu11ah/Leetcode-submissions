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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1 = bfs(p);
        vector<TreeNode*> v2 = bfs(q);

        if(v1.size() != v2.size()) return false;

        for(int i=0; i<v1.size(); i++){
            if(v1[i] && v2[i] && (v1[i]->val != v2[i]->val)) return false;
            else if(v1[i] && !v2[i]) return false;
            else if(!v1[i] && v2[i]) return false;
        }
        return true;
    }

    vector<TreeNode*> bfs(TreeNode* p){
        vector<TreeNode*> v;
        queue<TreeNode*> q;
        q.push(p);
        while(!q.empty()){
            TreeNode* nd = q.front();
            v.push_back(nd);
            q.pop();
            if(nd){
                q.push(nd->left);
                q.push(nd->right);
            }
        }
        return v;
    }
};
