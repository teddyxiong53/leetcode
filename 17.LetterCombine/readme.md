# 分析

```
2种方法：
1、递归法。通用。
2、笛卡尔积。python里有。
```



这个算法很简单，但是要把想法转成代码，感觉不好下手。

需要用递归的算法。

的确是有点难以想到这种算法，循环里面再递归。

```
class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if digits == '':
            return []
        mapping = {'2': ['a', 'b', 'c'],
                 '3': ['d', 'e', 'f'],
                 '4': ['g', 'h', 'i'],
                 '5': ['j', 'k', 'l'],
                 '6': ['m', 'n', 'o'],
                 '7': ['p', 'q', 'r', 's'],
                 '8': ['t', 'u', 'v'],
                 '9': ['w', 'x', 'y', 'z']}
        res = []
        self.backtracking(res,[],0, mapping,digits)
        return res

    def backtracking(self,res,subset,index, mapping,digits):
        if index == len(digits) :
            res.append(''.join(subset))
            return
        for i in mapping[digits[index]]:
            subset.append(i)
            self.backtracking(res,subset,index+1,mapping,digits)
            subset.pop()

s = Solution()
res = s.letterCombinations("234")
print(res)
```



这个代码写得太神奇了。

```
from itertools import product
from typing import List

class Solution:
    def letterCombinations(self, d: str) -> List[str]:
    	T = [0,0,'abc','def','ghi','jkl','mno','pqrs','tuv','wxyz']
    	return [] if len(d) == 0 else T[int(d)] if len(d) == 1 else ["".join(i) for i in product(*[T[int(i)] for i in d])]

s = Solution()
res = s.letterCombinations("234")
print(res)
```

其实主要还是靠product（笛卡尔积）这个方法。

```
a = "abc"
b = "def"
c = product(a,b)
for el in c:
    print(el)
```

这个输出是：

```
('a', 'd')
('a', 'e')
('a', 'f')
('b', 'd')
('b', 'e')
('b', 'f')
('c', 'd')
('c', 'e')
('c', 'f')
```

这个就很接近我们需要的东西了。

比较直观的写法是这样：

```
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        d = {'2': ['a', 'b', 'c'],
             '3': ['d', 'e', 'f'],
             '4': ['g', 'h', 'i'],
             '5': ['j', 'k', 'l'],
             '6': ['m', 'n', 'o'],
             '7': ['p', 'q', 'r', 's'],
             '8': ['t', 'u', 'v'],
             '9': ['w', 'x', 'y', 'z']}
        letters = []
        for i in digits:
            letters.append(d[i])
        l = list(product(*letters))
        result = []
        for i in l:
            result.append(''.join(i))
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

