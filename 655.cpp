// https://leetcode.com/problems/print-binary-tree/description/

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
    vector<vector<string>> printTree(TreeNode* root) {
        if (!root)
            return {};
        int height = GetHeight(root);
        vector<pair<string, int>> tmp = fun(root, 0, height);
        vector<vector<string>> ret(height, vector<string>(tmp.size()));
        for (int level = 0; level < height; ++level) {
            vector<string>& row = ret[level];
            // generate string row by level
            for (int i = 0; i < tmp.size(); ++i) {
                if (tmp[i].second == level)
                    row[i] = tmp[i].first;
            }
        }
        return ret;
    }
    
private:
    // node != nullptr
    // return pair: (first: val, second: level)
    // height: height of original tree
    vector<pair<string, int>> fun(TreeNode* node, int level, int height) {
        if (!node->left && !node->right) {
            int count = pow(2, height - level) - 1; // the result's size, which must be pow(2, height - level) - 1
            vector<pair<string, int>> tmp(count);
            tmp[count/2] = {to_string(node->val), level}; // node->val is in middle of tmp
            return tmp;
        }
        
        vector<pair<string, int>> left;
        vector<pair<string, int>> right;
        
        if (node->left)
            left = fun(node->left, level + 1, height);
        if (node->right)
            right = fun(node->right, level + 1, height);
        // if left or right is empty, the empty vector's size must be euqal to the non empty one by filled with {"", -1}.
        if (left.empty())
            left.resize(right.size(), {string(), -1});
        if (right.empty())
            right.resize(left.size(), {string(), -1});
        
        // construct the result vector.
        // ret = left + {node->val, current level} + right;
        vector<pair<string, int>> ret = move(left);
        ret.insert(ret.end(), {to_string(node->val), level});
        ret.insert(ret.end(), right.begin(), right.end());
        return ret;
    }
    
    int GetHeight(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + max(GetHeight(root->left), GetHeight(root->right));
    }
};