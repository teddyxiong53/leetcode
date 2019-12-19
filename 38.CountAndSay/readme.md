# 分析

这个题目有点难懂。

网上找了一下解释，看懂了。

```
数字1，对应的字符串是“1”。这个可以作为递归的终止条件。
数字2，对应的字符串是“11”。表示自己的前一个数字（就是数字1了）对应的字符串是1个1。
数字3，对应的字符串是“21”。表示自己的前一个数字（就是数字2了）对应的字符串是2个1.
数字4，对应的字符串是“1211”。表示自己的前一个数字（就是数字3了）对应的字符串的1个2,1一个1 。
数字5，对应的字符串是“111221”，表示自己的前一个数字（就是数字4了）对应的字符串是1个1,1个2,2个1 。
以此类推。
```

但是顺推也可以，反而递归，我找不到思路。

```
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        res = "1"
        n -=1
        while n> 0:
            cur = ""
            i = 0
            while i < len(res):
                cnt = 1
                while (i+1 < len(res)) and (res[i] == res[i+1]):
                    cnt += 1
                    i += 1
                cur += str(cnt) + res[i]
                i+=1
            res = cur

            n -= 1
        return res

s = Solution()
for i in range(1,30):
    print(s.countAndSay(i))
# print(s.countAndSay(2))
```

