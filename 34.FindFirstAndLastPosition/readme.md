# 分析

这个是从有序数组（元素可以重复）里找出某个数字的第一个位置和最后一个位置。

后面的题目，尽量都用c++来做。

因为限定了时间复杂度为对数。所以只能用二分查找。

```
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx = search(nums, 0, nums.size()-1, target);
        if(idx == -1) {
            return {-1,-1};
        }
        int left = idx, right = idx;
        while(left > 0 && nums[left-1] == nums[idx]) {
            --left;
        }
        while(right < nums.size()-1 && nums[right+1] == nums[idx]) {
            right++;
        }
        return {left,right};
    }
    int search(vector<int>& nums, int left, int right, int target) {
        if(left > right) {
            return -1;
        }
        int mid = left + (right-right)/2;
        if(nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            return search(nums, mid+1, right, target);
        } else {
            return search(nums, left, mid-1, target);
        }
    }
};
```

