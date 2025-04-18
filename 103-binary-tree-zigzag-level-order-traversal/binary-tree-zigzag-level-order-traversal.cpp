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
        if (root == NULL) {
            return vector<vector<int>>{};
        }

        queue<TreeNode*> level;
        level.push(root);
        
        vector<vector<int>> traversal;
        while(!level.empty()) {
            int sz = level.size();

            vector<int> currentLevel;
            while (sz--) {
                TreeNode* node = level.front();
                currentLevel.push_back(node->val);
                level.pop();

                if (node->left) {
                    level.push(node->left);
                }
                if (node->right) {
                    level.push(node->right);
                }
            }

            if (traversal.size() % 2) {
                reverse(currentLevel.begin(), currentLevel.end());
            }

            traversal.push_back(currentLevel);
        }

        return traversal;
    }
};