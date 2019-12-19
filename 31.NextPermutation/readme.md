# 分析

这个题目我理解了一会儿才懂。

需要复习一下排列组合的知识。

以123这3个数组的可能组合情况为例：

```
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
```



字典序

一本英语词典里的单词，排布顺序的依据是什么？

从头依次比较每个字母，第一个字母相同，就比较第二个，如此往复，直到找到不同的字符，字符靠前的排在前面。如果字母都相同，但是有一个短的，短的拍前面。



字典序算法是这样的：

```
以 358764为例说明：
1、在排列中，从右往左，找到第一个小于右邻的字符。我们找到5这个字符，我们把5的位置记下来a，a=1（索引位置）
2、重新从右往左，找到第一个比list[a]值大的值，找到是6，其位置记录为b，b=4.
3、把list[a]和list[b]交换位置。
4、把索引a后面的所有数据，按照升序排序一下。
```

边界情况：

```
1、第一步里，如果找不到左邻小于右邻的数，说明给定的排列已经是全排列里的最后一个了。
	这种情况，直接返回到第一个全排列。
2、
```

代码实现：

```
class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        寻找基于字典序的下一个排列。
        """
        l = len(nums)
    
        # 从右向左查询第一个小于右邻的元素
        for i in range(l-2, -1, -1):
            if nums[i+1] > nums[i]:
                break
        else: # 没有找到，说明为降序排列
            nums[:] = nums[::-1]
            return
    
        # 从右向左查询第一个大于nums[i]的元素
        for j in range(l-1, -1, -1):
            if nums[j] > nums[i]:
                break
    
        # 交换i和j
        nums[i], nums[j] = nums[j], nums[i]
    
        # i后面的序列进行反转
        nums[i+1:l] = nums[-1:i:-1]
```



参考资料

1、全排列问题

https://blog.csdn.net/qq_41056506/article/details/82659524