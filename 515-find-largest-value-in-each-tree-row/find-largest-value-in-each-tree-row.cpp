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
    vector<int> arr;
    void preOrder(TreeNode* Node,  int level){
        if (Node== NULL) return;
        if (arr.size()<=level) arr.push_back(INT_MIN);
        arr[level]=max(arr[level], Node->val);

        preOrder(Node->left, level+1);
        preOrder(Node->right, level+1);     
    }

    vector<int> largestValues(TreeNode* root) {
        if (root==NULL) return {};
        preOrder(root, 0);
        return arr;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();