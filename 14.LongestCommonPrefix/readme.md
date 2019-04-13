# 分析

这个问题不难。

所有字符串内容都是a到z的小写字母。

我自己写了一个版本，效率不行。

```
Runtime: 80 ms, faster than 25.60% of C online submissions for Longest Common Prefix.
Memory Usage: 213.4 MB, less than 6.06% of C online submissions for Longest Common Prefix.
```

代码是这样：

```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    #define LEN 1024*1024

    char *result = (char *)malloc(LEN);
    memset(result, 0, LEN);
    if(strsSize == 0) {
        strcpy(result, "");
        return result;
    }
    if(strsSize == 1) {
        return strs[0];
    }
    char *s0 = strs[0];
    char *s1 = strs[1];
    int len = 0;
    while(*s0 && *s1) {
        if(*s0 == *s1) {
            len ++;
        } else {
            break;
        }
        s0++;
        s1++;
    }
    if(len == 0) {
        strcpy(result, "");
        return result;
    }
    char *common = (char *)malloc(LEN);
    memset(common, 0, LEN);
    strncpy(common, strs[0], len);
    int i= 2;
    for(i=2; i<strsSize; i++) {
        for(;;) {
            if(strncmp(common, strs[i], len) == 0) {
                break;
            } else {
                len --;
            }
            if(len == 0) {
                goto end;
            }
        }
    }
    strncpy(result, common, len);
    return result;
end:
    strcpy(result, "");
    return result;
}

char *strs[] = {
    "flower","flow","flight"
};

int main()
{
    printf("%s\n", longestCommonPrefix(strs, 3));
}
```

我的代码写得太啰嗦了。

看看pezy的解法。

```
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty()) {
            return "";
        }
        for(size_t i=0; i<strs.front().size(); i++) {
            for(const auto &str : strs) {
                if(i==str.size() || str.at(i) !=strs.front().at(i)) {
                    return strs.front().substr(0, i);
                }
            }
        }
        return strs.front();
    }
};
```

的确c++在字符串和容器上，提供了很多的便利。



# C语言





# C++





# java

NA



# python

NA

# js

NA

