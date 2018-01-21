// https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/

/*
	Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

	Example 1:
		Input:
		nums = [1,3,1]
		k = 1
		Output: 0 
		Explanation:
		Here are all the pairs:
		(1,3) -> 2
		(1,1) -> 0
		(3,1) -> 2
		Then the 1st smallest distance pair is (1,1), and its distance is 0.

	Note:
		2 <= len(nums) <= 10000.
		0 <= nums[i] < 1000000.
		1 <= k <= len(nums) * (len(nums) - 1) / 2.
*/

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums.back() - nums.front();
        int mid = 0;
        int count = 0;
        while (low < high) {
            mid = (low + high)/2;
            count = countDistanceSmallerThan(nums, mid);
            if (count < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
    
private:
    // 计算 distance 小于等于 val 的 pair 的个数
    int countDistanceSmallerThan(const vector<int>& nums, int val) {
        int count = 0;
        int i = 0;
        int j = 0;
        for (; i < nums.size(); ++i) {
            while (j < nums.size() && nums[j] - nums[i] <= val)
                ++j;
            count += (j - i - 1);
        }
        return count;
    }
};