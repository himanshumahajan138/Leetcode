const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        switch (root->val) {
        case 0:
        case 1:
            return root->val;
        case 2:
            return evaluateTree(root->left) || evaluateTree(root->right);
        default:
            return evaluateTree(root->left) && evaluateTree(root->right);
        }
    }
};