# 分析

这个的难点在于不仅限制了时间复杂度为O(n)。还限制了空间复杂度为常数。

先看一个基本的解法，这个解法不满足空间复杂度，但是思路值得了解一下。

```
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 1;
        int n = nums.size();
        while(res <= n) {
            if(!st.count(res)) {
                return res;
            }
            res++;
        }
        return res;
    }
};
```

这个思路是用set，统计set里元素的个数。

既然空间复杂度是常数，那么就不能建立新的数组，只能在原有数组的基础上进行覆盖。

