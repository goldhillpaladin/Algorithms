// https://leetcode.com/problems/find-duplicate-subtrees/description/

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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> um;
        vector<TreeNode*> res;
        postOrder(root, um, res);
        return res;
    }
    
private:
    string postOrder(TreeNode* node, unordered_map<string, int>& um, vector<TreeNode*>& res) {
        if(!node)
            return string();
        string str = postOrder(node->left, um, res) + "," 
            + postOrder(node->right, um, res) + "," + to_string(node->val);
        if (um.count(str) == 0)
            um[str] = 1;
        else
            ++um[str];
        if (um[str] == 2)
            res.push_back(node);
        return str;
    }
};