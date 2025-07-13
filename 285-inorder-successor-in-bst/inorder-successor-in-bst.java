// https://leetcode.com/problems/inorder-successor-in-bst/?envType=weekly-question&envId=2025-07-08
class Solution {
    
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        
        TreeNode successor = null;
        
        while (root != null) {
            
            if (p.val >= root.val) {
                root = root.right;
            } else {
                successor = root;
                root = root.left;
            }
        }
        
        return successor;
    }
}