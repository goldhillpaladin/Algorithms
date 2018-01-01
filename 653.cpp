// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

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
    bool findTarget(TreeNode* root, int k) {
        vector<int> vec;
        vec.reserve(1024);
        travel(root, vec);
        int left = 0;
        int right = vec.size() - 1;
        while (left < right) {
            while (left < right && (vec[left] + vec[right]) > k)
                right--;
            if (left >= right)
                return false;
            if ((vec[left] + vec[right]) == k)
                return true;
            left++;
        }
        return false;
    }
    
private:
    void travel(TreeNode* root, vector<int>& vec) {
        if (!root)
            return;
        travel(root->left, vec);
        vec.push_back(root->val);
        travel(root->right, vec);
    }
};