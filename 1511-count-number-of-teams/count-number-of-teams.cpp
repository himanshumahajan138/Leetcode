class Solution {
public:
    struct Tree {
        Tree *left = nullptr, *right = nullptr;
        int val = 0, cnt_left = 0;
        Tree(int val) : val(val) {}
    };
    int numTeams(vector<int>& rating) {
        Tree left(rating.front()), right(rating.back());
        int res = 0, sz = rating.size();
        for (auto i = 1; i < sz - 1; ++i)
            insert(&right, rating[i]);
        for (auto i = 1; i < sz - 1; ++i) {
            remove(&right, rating[i]);
            int l_sm = count(&left, rating[i]), l_lg = i - l_sm;
            int r_sm = count(&right, rating[i]), r_lg = (sz - 1 - i - r_sm);
            res += l_sm * r_lg + l_lg * r_sm;
            insert(&left, rating[i]);
        }
        return res;
    }
    int count(Tree* root, int val) {
        if (root == nullptr)
            return 0;
        if (val < root->val)
            return count(root->left, val);
        return 1 + root->cnt_left + count(root->right, val);
    }
    Tree* insert(Tree* root, int val) {
        if (root == nullptr)
            return new Tree(val);
        if (val < root->val) {
            ++root->cnt_left;
            root->left = insert(root->left, val);
        } else
            root->right = insert(root->right, val);
        return root;
    }
    Tree* remove(Tree* root, int val) {
        if (root == nullptr)
            return nullptr;
        if (root->val == val) {
            if (root->left == nullptr)
                return root->right;
            auto rightmost = root->left;
            while (rightmost->right != nullptr)
                rightmost = rightmost->right;
            rightmost->right = root->right;
            return root->left;
        }
        if (val < root->val) {
            --root->cnt_left;
            root->left = remove(root->left, val);
        } else
            root->right = remove(root->right, val);
        return root;
    }
};