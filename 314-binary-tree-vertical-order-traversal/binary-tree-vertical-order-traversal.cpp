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
    void doInorderTraversal(int row, int col, TreeNode* node, map<int, map<int, vector<int>>> &values) {
        if (node == NULL) {
            return;
        }

        values[col][row].push_back(node->val);
        doInorderTraversal(row + 1, col - 1, node->left, values);
        doInorderTraversal(row + 1, col + 1, node->right, values);
    }

public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, map<int, vector<int>>> values;
        doInorderTraversal(0, 0, root, values);
        
        vector<vector<int>> traversal;
        for (auto col : values) {
            vector<int> level;
            for (auto row : col.second) {
                for (auto value : row.second) {
                    level.push_back(value);
                }
            }
            traversal.push_back(level);
        }

        return traversal;
    }
};