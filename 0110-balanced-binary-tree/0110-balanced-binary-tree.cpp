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
    int balanced = true;
    int getDepth(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);

        if (abs(leftDepth - rightDepth) > 1) {
            balanced = false;
        }

        return max(leftDepth, rightDepth) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        // height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
        
        // having no children means you are balanced
        if (root == nullptr) {
            return true;
        }

        getDepth(root);

        return balanced;
    }
};