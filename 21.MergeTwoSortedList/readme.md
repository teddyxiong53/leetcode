# 分析

合并2个排序好的链表。

找到一个python的方案。思路是把值拷贝出来重新构造一个新的链表。

优点是简单易懂，缺点是效率不太高。

```
class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = new_list = ListNode(0)
        node1 = l1
        node2 = l2
        while node1 or node2:
            if node1 == None:
                new_list.next = node2
                break
            elif node2 == None:
                new_list.next = node1
                break
            elif node1.val > node2.val:
                new_list.next = new_list = ListNode(node2.val)
                node2 = node2.next
            else:
                new_list.next = new_list = ListNode(node1.val)
                node1 = node1.next
        return head.next
```



自己写的一个方案。可以通过测试。

```
class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(-1)
        p = dummy
        while l1 or l2:
            if l1 and l2 and l1.val <= l2.val:
                p.next = l1
                l1 = l1.next
            elif l1 and l2 and l1.val > l2.val:
                p.next = l2
                l2 = l2.next
            elif l1:
                p.next = l1
                l1 = l1.next
            elif l2:
                p.next = l2
                l2 = l2.next
            p = p.next

        return dummy.next
```



