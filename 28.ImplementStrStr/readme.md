# 分析

这个是实现strstr函数。

特别说明了，当要查找的子字符串为空的时候，返回0。

否则返回第一次出现的位置的索引。

```
aabbcc
里搜索
bc
cd
cc
```

对str，没有必要索引到最后，索引到len(str) - len(sub)的位置处就够了。

这个点是关键。

```
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        len1 = len(haystack)
        len2 = len(needle)
        if len2 == 0:
            return 0
        if len2 > len1:
            return -1
        i = 0
        while i <= len1-len2:
            j = 0
            while j < len2:
                if (haystack[i+j] != needle[j]):
                    break
                j += 1
                if j == len2:
                    return i
            i += 1
        return -1
```



