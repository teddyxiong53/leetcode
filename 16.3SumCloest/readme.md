# 分析

这个是跟3Sum类似，但是增加了难度，题目的意思是让3个数之和，最接近某个给定值（3Sum相当于给定值为0的特例）。

思路还是一样，靠左右滑动。

```
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        sz = len(nums)
        closet = nums[0] + nums[1] + nums[2]
        diff = abs(closet-target)
        for i in range(0, sz):
            l = i + 1
            r = sz -1

            while l < r:
                sum = nums[i] + nums[l] + nums[r]
                newDiff = abs(sum-target)
                if (newDiff < diff) :
                    diff = newDiff
                    closet = sum
                if sum < target:
                    l += 1
                else :
                    r -= 1
        return closet

```



# C语言

NA



# C++

NA



# java

NA



# python

NA

# js

NA



参考资料

1、[LeetCode] 16. 3Sum Closest 最近三数之和

https://www.cnblogs.com/grandyang/p/4510984.html