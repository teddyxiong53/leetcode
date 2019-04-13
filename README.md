尽量实现5种语言的版本：

```
c
c++
java
python
js
```

实现的顺序也按照这个来。首先实现C语言的版本。然后c++，依次类推。

按照题目编号来做。

文件名统一都叫Solution.x。x表示对应的后缀。

主要还是用C语言做，其他的主要看思路有什么不一样的。



```
01 Two Sum
	求一个数组里，和等于指定值的2个数的下标。
	ok
02 Add Two Numbers
	2个数组，把里面的成员依次相加，得到一个结果。是大数加法的基础了。
	ok
03 Longest substring
	求一个字符串里，没有相同字符的最长的字符串的长度。
	值得反复看。二层循环。
04 Media of two sorted array。
	这个重点是考虑全面。看官方分析里的公司挺头疼的。
	值得反复学习。
	先暂时跳过吧。
05 Longest Palindromic Substring
	找出最长的回文字符串。
	马拉车算法，这个重点是分析，算法实现反而不是重点。
06 zigzag
	这个是把一个字字符串按Z字形排列。没有什么意思。不看。
07 Reverse Integer
	翻转一个给定的整数。
08 String to Integer
	自己实现atoi函数。
09 Palindromic Number
	回文数。回文数，特点就是reverse之后，值和reverse之前相等。
	可以复用07的函数。
10 Regular Expression Matching
	实现简单的正则匹配。只匹配*和. 。
	跳过。
11.ContainerWithMostWater
	这个暴力法很容易写。一次循环的也实现了。
12.IntegerToRoman
	这个是整数转罗马数字。
13.RomanToInteger
	是上一题的逆向。不做了。
	还是做一下，还是不一样的。还是差不多，查表法可以解决。
14.LongestCommonPrefix
	最长的相同前缀。
15.3Sum
	给定一个数组，求三个数之和为0的组合。
	这个用C语言来做，还真是不方便。
	用c++吧。
	
```



参考资料

1、

https://github.com/pezy/LeetCode

