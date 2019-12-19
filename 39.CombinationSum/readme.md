# 分析

这种要求返回所有符合要求的解的问题，基本上都要用到递归。

解题套路是一样的。

就另外写一个递归版本的函数。

```
class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        out = []
        self.combinationSumDFS(candidates, target, 0, out, res)
        return res

    def combinationSumDFS(self, candidates:list, target, start, out:list, res:list ):
        if target < 0:
            return
        if target == 0:
            res.append(out)
            print(out)
            return
        i = start
        while i < len(candidates):
            out.append(candidates[i])
            self.combinationSumDFS( candidates, target-candidates[i], i, out, res)
            out.pop(-1)
            i += 1
import copy
s = Solution()
res = []
res = copy.deepcopy(s.combinationSum([2,3,5,7], 7))
print(res)
```

这个是把Grandyang的代码，c++版本的改成python版本。可以找出来，但是不完全正确。

c++版本的测试正常。但是target太大，而candidates里面的内容太小，则运行会卡住很久。

例如candidate里面有2，然后target给10000，由5000个2可以组成10000的。

但是这样递归的深度就非常深了。



到leetcode的讨论里找工作正常的python代码。如下：

```
from bisect import bisect_left
from typing import List
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
		# we need to sort candidates for easier filtering
        result = self._combinationSum(sorted(candidates), target, [])
        return list(result)

    def _combinationSum(self, candidates: List[int], target: int, track: List[int]):
        i = bisect_left(candidates, track[-1]) if track else 0
		# ignore candidates that are lower than last used
		# it will help us to have sorted order of result
        for c in candidates[i:]:
            if c == target:
				# python lists are optimised for appending/popping last element
				# so this operation should be quite fast
                track.append(c)
                yield tuple(track)
                track.pop(-1)
            elif c < target:
                track.append(c)
                yield from self._combinationSum(candidates, target - c, track)
                track.pop(-1)
            else:
                break
s = Solution()
print(s.combinationSum([2,3,5,7],7))
```

这个python的更加复杂。

在看Grandyang的其他解法。

可以直接对combinationSum进行递归，不用另外再写一个递归函数。



