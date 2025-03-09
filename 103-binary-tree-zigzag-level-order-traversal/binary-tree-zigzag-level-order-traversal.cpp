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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool flag = 0;
        
        while(!q.empty()) {
            
            int sz = q.size();
            vector<int> v;
            
            while(sz--) {
                TreeNode* node = q.front(); 
                v.push_back(node->val);
                q.pop();
                
                if(node->left) q.push(node->left); 
                if(node->right) q.push(node->right);
            }
            
            if(flag) reverse(v.begin(), v.end());
            flag = 1 - flag;
            ans.push_back(v);
        }
        
        return ans;
    }
};