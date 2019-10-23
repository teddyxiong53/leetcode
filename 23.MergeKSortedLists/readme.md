# 分析

这个题目，就是可以用多种算法来解决。



我一看之下，觉得比较麻烦。

但是网上看到一个思路，真的是鬼才思想。我按照这个思想实现了一个python版本，效率还比较高，超过了90%的python实现。

其实思路很简单，就是把所有链表的值取出来，然后放入到一个数组里。

然后根据这个数组重新生成一个链表进行返回。

我实现如下：

```
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        def create_list(arr):
            dummy = ListNode(0)
            root = dummy
            for el in arr:
                n = ListNode(el)
                dummy.next = n
                dummy = dummy.next
            return root.next
        arr = []
        for l in lists:
            while l:
                arr.append(l.val)
                l = l.next
        # sort arr
        arr.sort()
        # generate a list
        return create_list(arr)
```

我又看了一下，这个思路就是官方的solution里写的 。

看看参考实现跟我的有什么不同。没什么不同，基本一致。

这个方式对我来说，还是真是有启发，不涉及什么指针操作，真是曲线救国的方式。



## 第二种思路

这个是从k个链表里，各取一个数，进行比较，把最小的那个放到结果里。

然后被取走数的那个链表，继续往后取数。

这个思路看起来还比较清晰，但是怎么转化成对应的代码呢？





可以用分治法，分治法就是两两合并。



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

