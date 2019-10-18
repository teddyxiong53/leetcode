# 分析

这个是生成配对的括号字符串。要合法。

给定参数是括号的组数。

简单点来看，可以复用前面的第20题那个Valid判断。不过效率就不会高了。

可以先运行一下，看看这个思路的效率怎么样。

怎样生成所有情况呢？

左右括号，因为只有两种情况，所以跟二进制的0和1是对应的。

可以用递归的方式来生成。

递归的终止条件是什么？已经生成长度达到2*n了。

```
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        # generate all result, then judge
        def generate(A=[]):
            if len(A) == 2*n:
                if isValid(A):
                    res.append(''.join(A))
            else:
                A.append('(')
                generate(A)
                A.pop()
                A.append(')')
                generate(A)
                A.pop()

        def isValid( str):
            tmp = []
            for c in str:
                if c == '(':
                    tmp.append(c)
                if c == ')':
                    try:
                        if tmp[-1] == '(':
                            tmp.pop()
                    except:
                        return False
            if len(tmp) == 0:
                return True
            return False
        res = []
        generate()
        return res
```



参考资料

1、22. Generate Parentheses

https://blog.csdn.net/u012033124/article/details/80532460



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

