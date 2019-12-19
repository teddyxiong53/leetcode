# 分析

这个是两两交互链表元素。

明确说了不允许对节点的值进行修改（如果不约束，这个问题就很简单）。

网上找的直观的解法。

```
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        dummy = ListNode(0)
        dummy.next = head
        p = dummy
        
        while p.next and p.next.next:
            node1 = p.next
            node2 = p.next.next
            temp = p.next.next.next
            
            p.next = node2
            p.next.next = node1
            p.next.next.next = temp
            
            p = p.next.next
        return dummy.next
```

还有递归的解法。

```
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        t = head.next
        head.next = self.swapPairs(head.next.next)
        t.next = head
        return t
```







