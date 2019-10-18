# 分析

这个是求4个数之和，最解决目标数。

4个数的，和3个数的，有什么不同？

3个数，可以定住一个，动2个。这个策略在4个数的时候，怎么调整？

自己写出来了。就是再多套一层循环。相当于固定2个数，移动2个数的样子。

```
from typing import List

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        sz = len(nums)
        if sz< 4:
            return []
        nums.sort()
        result = []
        for i in range(0,sz):
            for j in range(i+1,sz):
                l = j+1
                r = sz -1
                while l< r:
                    sum = nums[i]+nums[j]+nums[l]+nums[r]
                    if  sum > target:
                        r -= 1
                    elif sum < target:
                        l += 1
                    else:
                        tmp = [nums[i], nums[j], nums[l], nums[r]]
                        tmp.sort()
                        if tmp not in result:
                            result.append(tmp)
                        l += 1
                        r -= 1

        return result
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

