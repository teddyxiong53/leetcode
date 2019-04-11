# C语言

```
int lengthOfLongestSubstring(char* s) {
    int i,j;
    int len = strlen(s);
    int curLen = 0;
    int maxLen = 0;
	int first = 0;
    for(int i=1; i<len; i++) {
        for(j=first; j<i; j++) {
            if(s[i] == s[j]) {
                first = j+1;
				break;
            }
            
        }
        if(maxLen < (i-first+1)) {
               maxLen = (i-first+1);
        }
    }
    return maxLen;
}
```

我开始这么写，是错的。

对于abcabcbb。我的这种写法会判断abcbb，没有找到重复的a，所以认为这个是最长的字符串。

但是不对。里面还要再嵌套一层循环才行。不是，再嵌套一层循环还是解决不了问题。

我的这个思路是错的。

网上的解法是这样的：

```
int lengthOfLongestSubstring(char *s)
{
    int len = strlen(s);
    int *set = (int *)malloc(128 * sizeof(int));
    memset(set, 0, 128 * sizeof(int));
    int i = 0, j = 0;
    int maxlen = 0;
    while (i < len && j < len)
    {
        if (!set[s[j]])
        {
            set[s[j++]] = 1;
            if (j - i >= maxlen)
            {
                maxlen = j - i;
            }
        }
        else
        {
            set[s[i++]] = 0;
        }
    }

    return maxlen;
}
```

是靠128个ASCII码字符的重复情况来做的。

很巧妙。

有个这样的c++解法，跟我的差不多，但是区别在哪里？

```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longestLength = 0;
        int currentIndex = 0;
        int currentLength = 0;
        for(unsigned i = 0; i < s.size(); ++i){
            for(unsigned j = currentIndex; j < currentIndex + currentLength; ++j){
                if(s[i] == s[j]){
                    currentLength -= (j + 1 - currentIndex);
                    currentIndex = j + 1;
                    break;
                }
            }
            ++currentLength;
            if(currentLength > longestLength){
                longestLength = currentLength;
            }
        }
        return longestLength;
    }
};
```

它这个遍历逻辑是，往后挪一个字符的位置，然后就把前面的遍历一次，

前面的开始点，也在根据情况往后移动。



我把java版本的，改成C语言版本的。

```
int lengthOfLongestSubstring(char* s) {
    int i,j;
    int len = strlen(s);
    if(len == 0) {
        return 0;
    }
    int curLen = 0;
    int maxLen = 1;
	int first = 0;
    for(int i=1; i<len; i++) {
        for(j=first; j<i; j++) {
            if(s[i] == s[j]) {
                first = j+1;
				break;
            }
            
        }
        if(maxLen < (i-first+1)) {
               maxLen = (i-first+1);
        }
    }
    return maxLen;
}
```

这个是效率最高的。

```
Runtime: 4 ms, faster than 100.00% of C online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 7 MB, less than 100.00% of C online submissions for Longest Substring Without Repeating Characters.
```



# C++

```
class Solution {
private:
    int isRepeating(string& s, int start, int end){
        for (int i = start ; i < end ; i++)
            if (s[i] == s[end])
                return i;
        return -1;
    } 
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int len = 0, slow = 0;         
        for ( int i = 1 ; i < n ; i++ ){
            int found = isRepeating(s,slow,i);
            if (found != -1){
                len = i-slow > len ? i-slow : len ;
                slow = found + 1;
            }
        }
        len = n-slow > len ? n-slow : len;
        
        return len;
    }
};
```





# java





# python

NA

# js

NA

