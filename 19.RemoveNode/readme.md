# 分析

这个是移除链表的第N个元素。从后往前数的。

虽然看起来不难，但是有些情况考虑不充分。

```
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        # get the len
        pre = head
        cur = head
        i = 0
        while i < n:
            cur = cur.next
            i += 1
        if cur == None:
            return head.next
        while cur.next:
            cur = cur.next
            pre = pre.next
        pre.next = pre.next.next
        return head
```




