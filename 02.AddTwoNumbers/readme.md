

# 分析

关键在于傀儡节点。

```
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(-1)
        cur = dummy
        over = 0
        while l1 or l2:
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0

            s = v1 + v2 + over

            if s >= 10:
                over = 1
            else:
                over = 0
            cur.next = ListNode(s%10)
            cur = cur.next
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        if over:
            cur.next = ListNode(1)
        return dummy.next

def print_list(lst):
    while lst:
        print(lst.val)
        lst = lst.next

s = Solution()
n10 = ListNode(1)
n11 = ListNode(4)
n12 = ListNode(7)

n10.next = n11
n11.next = n12

n20 = ListNode(3)
n21 = ListNode(6)
n22 = ListNode(9)
n23 = ListNode(1)
n20.next = n21
n21.next = n22
n22.next = n23

print('list1:')
print_list(n10)
print('list2:')
print_list(n20)

res = s.addTwoNumbers(n10, n20)
print("result:")
print_list(res)
```

