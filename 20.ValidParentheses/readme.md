# 分析

这个是判断三种括号是否配对合法。

被归类为easy。但是我看到是觉得没有什么思路的。

有个思路是这样：使用栈的方式。

碰到一个左括号，入栈，碰到一个右括号，把左括号出栈。

最后看栈里面是不是空的，不是空的，则说明有问题。

自己写的。用list来模拟栈。tmp[-1]这个是查看栈顶。

```
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        tmp = []
        left = ['(', '[', '{']
        right = [')', ']', '}']
        if len(s)%2!=0:
            return False
        for i in s:
            if i in left:
                tmp.append(i)
            if i in right:
                # get the top of stack
                try:
                    l = tmp[-1]
                    if left.index(l) == right.index(i):
                        tmp.pop()
                    else:
                        return False
                except:
                    return False
        if len(tmp) != 0:
            return False
        return True
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

