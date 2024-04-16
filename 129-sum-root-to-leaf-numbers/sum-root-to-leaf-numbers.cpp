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
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

       
        return sumNumbersHelper(root,0);
    }

private:
    int sumNumbersHelper(TreeNode* node, int currentNumber) {
        if (node == nullptr) {
            return 0;
        }

        
        currentNumber = currentNumber*10 + node->val;

        
        if (node->left == nullptr && node->right == nullptr) {
            return currentNumber;
        }

       
        int leftSum = sumNumbersHelper(node->left, currentNumber);
        int rightSum = sumNumbersHelper(node->right, currentNumber);

        return leftSum + rightSum;  
    }
};