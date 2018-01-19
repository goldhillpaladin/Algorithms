#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void Helper(std::vector<char>& arr, size_t index, std::vector<std::string>& result) {
    if (index >= arr.size() - 1) {
        result.push_back(std::string(arr.begin(), arr.end()));
        return;
    }
    for (size_t i = index; i < arr.size(); ++i) {
        std::swap(arr[index], arr[i]);
        Helper(arr, index + 1, result);
        std::swap(arr[index], arr[i]);
    }
}

// arr: 存放初始数据
// 返回 arr 对应的全排列集合
std::vector<std::string> FullPermutation(std::vector<char>& arr) {
    std::vector<std::string> result;
    Helper(arr, 0, result);
    return result;
}

void test() {
    std::vector<char> arr = { 'A', 'B', 'C' };
    auto result = FullPermutation(arr);
    for (const auto& str : result)
        std::cout << str.c_str() << std::endl;
}

int main() {
	test();
	return 0;
}