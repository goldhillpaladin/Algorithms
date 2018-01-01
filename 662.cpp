// https://leetcode.com/problems/maximum-width-of-binary-tree/description/

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
	// 按层遍历二叉树，记住每个节点在当前层的 index 即可
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        
        int level_size = 1;
        queue<pair<TreeNode*, int>> ques[2];
        ques[0].push({root, 0}); // k: node;  v: index in current level
        
        int max_width = 0;
        int level = 0;
        int start = 0;
        int end = 0;
        while (!ques[level % 2].empty()) {
            auto& que1 = ques[level % 2];
            auto& que2 = ques[(level + 1) % 2];
            start = que1.front().second;
            while (!que1.empty()) {
                const auto& kv = que1.front();
                if (kv.first->left)
                    que2.push({kv.first->left, 2 * kv.second});
                if (kv.first->right)
                    que2.push({kv.first->right, 2 * kv.second + 1});
                if (que1.size() == 1)
                    end = kv.second;
                que1.pop();
            }
            max_width = max(max_width, end - start + 1);
            ++level;
        }
        return max_width;
    }
};