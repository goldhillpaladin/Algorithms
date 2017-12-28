// 题目地址：https://leetcode.com/problems/longest-univalue-path/description/

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
    int longestUnivaluePath(TreeNode* root) {
        int lup = 0;
        dfs(root, lup);
        return lup;
    }
    
    // 返回值：node 出发向下的最长 univalue 单链
    int dfs(TreeNode* node, int& lup){
        if(!node)
            return 0;
        
        int left = 0; // node 向左下方的 value 相同的节点数，不包括 node 本身
        int right = 0; // node 向右下方的 value 相同的节点数，不包括 node 本身
        int left_child_len = 0; // left child 出发向下的最长 univalue 单链的节点数
        int right_child_len = 0; // right child 出发向下的最长 univalue 单链的节点数
        
        if(node->left)
            left_child_len = dfs(node->left, lup);
        if(node->right)
            right_child_len = dfs(node->right, lup);
        if(node->left && node->left->val == node->val)
            left = left_child_len;
        if(node->right && node->right->val == node->val)
            right = right_child_len;
        lup = max(lup, left + right);
        
        return max(left, right) + 1;
    }
};