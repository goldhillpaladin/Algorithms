// https://leetcode.com/problems/maximum-binary-tree/description/

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return fun(nums.begin(), nums.end());
    }
    
private:
    TreeNode* fun(vector<int>::iterator begin, vector<int>::iterator end) {
        if (begin == end)
            return nullptr;
        vector<int>::iterator max_iter = max_element(begin, end);
        TreeNode* node = new TreeNode(*max_iter);
        node->left = fun(begin, max_iter);
        node->right = fun(max_iter + 1, end);
        return node;
    }
};