#include <algorithm>
#include <iostream>
#include <vector>

// 找出字典序下， nums 的下一个排列，并存放在 nums 中，返回 true
// 如果下一个排列不存在，则不改变 nums，并返回 false
bool NextPermutation(std::vector<int>& nums) {
    if (nums.size() <= 1)
        return false;
    int k = nums.size() - 2;
	// k 是满足 nums[k] < nums[k+1] 的最大下标值
	// 显然，nums[k+1]...nums[nums.size()-1] 是一个非增序序列
    for (; k >= 0 && nums[k] >= nums[k+1]; --k);
    if (k < 0) // 如果 k 不存在，说明当前排列已经是字典序最大的排列
        return false;
    int l = nums.size() - 1;
    while (k < l && nums[k] >= nums[l]) // 在 nums[k+1]...nums[nums.size()-1] 中，nums[l] 是大于 nums[k] 的值中最小的
        --l;
    std::swap(nums[k], nums[l]); // 交换后，显然 nums[k+1]...nums[nums.size()-1] 还是是一个非增序序列
    std::reverse(nums.begin() + k + 1, nums.end()); // nums[k+1]...nums[nums.size()-1] 变成增序序列
    return true;
}

void PrintPermutation(const std::vector<int>& nums) {
    for (int num : nums)
        std::cout << num;
    std::cout << std::endl;
}

void test1() {
    std::vector<int> nums = {1, 3, 8, 7, 6, 5, 4, 2};
    std::cout << "src: ";
    PrintPermutation(nums);
    bool ret = NextPermutation(nums);
    if (!ret)
        std::cout << "no next permutation\n";
    PrintPermutation(nums);
    std::cout << std::endl;
}

void test2() {
    std::vector<int> nums = {1, 2, 3};
    std::cout << "src: ";
    PrintPermutation(nums);
    while (NextPermutation(nums))
        PrintPermutation(nums);
    std::cout << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}