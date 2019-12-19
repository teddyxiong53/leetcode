# 分析

这个题目的确挺难搞的。

给定的参数：

1、一个字符串s。

2、一个字符串数组words。里面包含的元素，都是长度相同的短字符串。（这些短字符串的内容可以相同，这个是关键）

目的：

让数组里的所有字符串按各种可能的方式连接起来，得到一个整体字符串，然后在给定的字符串里去搜索这个拼接的字符串，如果找到了，返回对应的索引。

不过也有一种暴力解法的思路，利用排序。

把words里的所有内容取出来，排序，拼接成一个整体字符串。

然后从s里取对应长度的一个子串出来，截断成words里的元素的长度，再排序，然后把得到的结果，跟前面得到的字符串进行比较，如果相同，就说明找到一个。

```
class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if len(words)==0 or len(s)==0:
            return []
        if len(s) < len(''.join(words)):
            return []
        result = []
        words_cat = ''.join(sorted(words))
        word_len = len(words[0])
        words_count = len(words)
        words_len = len(words_cat)
        for i in range(len(s) - words_len + 1):
            s_sub = []
            for j in range(words_count):
                s_sub.append(s[i+word_len*j : i+word_len*(j+1)])
            s_sub = ''.join(sorted(s_sub))
            if s_sub == words_cat:
                result.append(i)
        return result

s = Solution()
res = s.findSubstring("foobarbaz", ['foo', 'bar'])
print(res)
```

