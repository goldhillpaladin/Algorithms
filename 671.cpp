// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/

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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root)
            return -1;
        auto a = smallerVal(root);
        if(a.first == a.second)
            return -1;
        return a.second;
    }
    
private:
    // 找出以 node 为根节点的树中最小的两个值。如果所有值都相等，则返回相等的两个值。
    // 返回值：first 最小；second 第二小。
    pair<int, int> smallerVal(TreeNode* node) {        
        if(!node->left)
            return pair<int, int>(node->val, node->val);
        
        if (node->left->val == node->right->val) { // 左右子节点的val相等
            auto a = smallerVal(node->left);
            auto b = smallerVal(node->right);
            set<int> st = {a.first, a.second, b.first, b.second};
            auto iter = st.begin();
            if(st.size() == 1)
                return {*iter, *iter};
            else
                return {*iter, *(++iter)};
        }
        
        TreeNode* equal_child = nullptr;
        TreeNode* bigger_child = nullptr;
        if (node->left->val > node->right->val) {
            equal_child = node->right;
            bigger_child = node->left;
        } else {
            equal_child = node->left;
            bigger_child = node->right;
        }
        auto a = smallerVal(equal_child);
        if(a.second != node->val)
            return pair<int, int>(node->val, min(bigger_child->val, a.second));
        else
            return pair<int, int>(node->val, bigger_child->val);
    }
};