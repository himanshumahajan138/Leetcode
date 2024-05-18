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
    int traverse(TreeNode* r, int& moves) {
        if (r == nullptr)
            return 0;
        int left = traverse(r->left, moves), right = traverse(r->right, moves);
        moves += abs(left) + abs(right);
        return r->val + left + right - 1;
    }
    int distributeCoins(TreeNode* r, int moves = 0) {
        traverse(r, moves);
        return moves;
    }
};