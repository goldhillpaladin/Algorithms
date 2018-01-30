// https://leetcode.com/problems/decode-ways/description/

/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0')
            return 0;
        
        // dp[i] 代表字符串为 s[0...i] 时可以表示的组合的数量，其中：
        // dp[i][0]: 总的组合数量
        // dp[i][1]: s[i]用于表示字母A(1)时，组合的数量
        // dp[i][2]: s[i]用于表示字母B(2)时，组合的数量
        vector<vector<int>> dp(s.size(), vector<int>(3, 0));
        dp[0][0] = 1;
        if (s[0] == '1')
            dp[0][1] = 1;
        if (s[0] == '2')
            dp[0][2] = 1;
        
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '1')
                dp[i][1] = dp[i-1][0];
            if (s[i] == '2')
                dp[i][2] = dp[i-1][0];
            
            if (s[i] != '0')                // s[i] 不为 '0' 时，即为 "1" - "9"，可以代表 A-I
                dp[i][0] += dp[i-1][0];
            dp[i][0] += dp[i-1][1];         // s[i-1] 和 s[i] 一起，可以组成 "10" - "19"
            if (s[i] >= '0' && s[i] <= '6') // s[i-1] 和 s[i] 一起，可以组成 "20" - "26"
                dp[i][0] += dp[i-1][2];
        }
        return dp.back()[0];
    }
};