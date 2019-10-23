# 分析

这个题目显示是容易，但是我读题目没太读懂。

不过看解法也的确出乎我的想法。

是靠2个索引来做的。

并没有把那些元素删掉，只是被交换往后挪了。

```
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i = 0
        for j in range(len(nums)):
            if nums[j] != val:
                nums[i] = nums[j]
                i += 1
        return i
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

