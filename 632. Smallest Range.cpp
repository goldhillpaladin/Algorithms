// https://leetcode.com/problems/smallest-range/description/

/*
You have k lists of sorted integers in ascending order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.

Example 1:
Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].

Note:
The given list may contain duplicates, so ascending order means >= here.
1 <= k <= 3500
-105 <= value of elements <= 105.
*/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // {value, k, i}
        typedef array<int, 3> Element;
        auto cmp = [](const Element& a, const Element& b) {
            return a[0] > b[0];
        };
        priority_queue<Element, vector<Element>, decltype(cmp)> pq(cmp);
        vector<int> range = {-200000, 200000};
        int max_v = -200000;
        for (int k = 0; k < nums.size(); ++k) {
            auto& row = nums[k];
            pq.push({row[0], k, 0});
            max_v = max(max_v, row[0]);
        }
        
        for (;;) {
            Element ele = pq.top();
            if (max_v - ele[0] < range[1] - range[0])
                range = {ele[0], max_v};
            
            if (ele[2] == nums[ele[1]].size() - 1)
                break;
            
            pq.pop();
            int next_v = nums[ele[1]][ele[2] + 1];
            pq.push({next_v, ele[1], ele[2] + 1});
            max_v = max(max_v, next_v);
        }
        
        return range;
    }
};