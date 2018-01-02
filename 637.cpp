// https://leetcode.com/problems/average-of-levels-in-binary-tree/description/

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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root)
            return {};
        vector<double> averages;
        queue<TreeNode*> ques[2];
        ques[0].push(root);
        int level = 0;
        long long level_sum = 0;
        int level_count = 0;
        while (!ques[level % 2].empty()) {
            auto& que1 = ques[level % 2];
            auto& que2 = ques[(level + 1) % 2];
            level_sum = 0;
            level_count = 0;
            while (!que1.empty()) {
                auto& cur = que1.front();
                level_sum += cur->val;
                ++level_count;
                if (cur->left)
                    que2.push(cur->left);
                if (cur->right)
                    que2.push(cur->right);
                que1.pop();
            }
            averages.push_back(level_sum / (double)level_count);
            ++level;
        }
        return averages;
    }
};