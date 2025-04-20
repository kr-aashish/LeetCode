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
    void processVal(int &val, int &currStreak, int &maxStreak, int &currVal, vector<int> &mode) {
        if (currVal == val) {
            currStreak++;
        } else {
            currStreak = 1;
            currVal = val;
        }

        if (currStreak > maxStreak) {
            maxStreak = currStreak;
            mode = {currVal};
        } else if (currStreak == maxStreak) {
            mode.push_back(currVal);
        }
    }

public:
    vector<int> findMode(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* prev = NULL;

        int currStreak = 0;
        int maxStreak = 0;
        int currVal = curr->val;
        vector<int> mode = {currVal};

        while (curr != NULL) {
            if (curr->left == NULL) {
                processVal(curr->val, currStreak, maxStreak, currVal, mode);
                curr = curr->right;
            } else {
                prev = curr->left;
                while (prev->right != NULL and prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = NULL;
                    processVal(curr->val, currStreak, maxStreak, currVal, mode);
                    curr = curr->right;
                }
            }
        }

        return mode;
    }
};