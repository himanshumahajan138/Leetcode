const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    // O(n) time | O(d) space
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* dummyRoot = new TreeNode(INT_MIN, root, nullptr);
        dfs(dummyRoot, 0, val, depth);

        root = dummyRoot->left;
        delete dummyRoot;
        return root;
    }

    void dfs(TreeNode* node, int curDepth, int val, int targetDepth) {
        if (!node) return;

        if (curDepth == targetDepth - 1) {
            auto originalLeft = node->left;
            auto originalRight = node->right;

            auto bufferLeft = new TreeNode(val, originalLeft, nullptr);
            auto bufferRight = new TreeNode(val, nullptr, originalRight);
            node->left = bufferLeft;
            node->right = bufferRight;
            return;
        }
        
        dfs(node->left, curDepth + 1, val, targetDepth);
        dfs(node->right, curDepth + 1, val, targetDepth);
    }
};