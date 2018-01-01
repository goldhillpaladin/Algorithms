// https://leetcode.com/problems/trim-a-binary-search-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root)
            return nullptr;
        if (inRange(root->val, L, R)) {
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            return root;
        } else {
            if (root->val < L)
                return trimBST(root->right, L, R);
            else
                return trimBST(root->left, L, R);
        }
    }
    
private:
    bool inRange(int val, int L, int R) {
        return val >= L && val <= R;
    }
};