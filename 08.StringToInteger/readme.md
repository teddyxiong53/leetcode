# 分析

首先把前面的空格都去掉。

如果不合法，就返回0 。

超出int范围，则返回最大值或者最小值。

我自己写的第一个版本。

```
int myAtoi(char* str) {
    //skip white space
    while(*str == ' ') {
        str ++;
    }
    if(strlen(str) == 0) {
        return 0;
    }
    //check first digit
    if(*str != '+' && *str != '-' && !(*str >= '0' && *str <= '9')) {
        return 0;
    }
    long result = 0;
    int sign = 0;
    if(*str == '-') {
        sign = 1;
        str ++;
    }
    if(*str == '+') {
        str ++;
    }

    while(*str) {
        int d = *str;
        if(d >= '0' && d<='9') {
            result *= 10;
            result += d - '0';
        } else {
            break;
        }
        str ++;
    }
    if(sign) {
        result *= -1;
    }
    if(result >= INT_MAX) {
        result = INT_MAX;
    }
    if(result <= INT_MIN) {
        result = INT_MIN;
    }
    return result;
}
```

报错：

```
Line 26: Char 20: runtime error: signed integer overflow: 2000000000000000000 * 10 cannot be represented in type 'long int' (solution.c)
```

改一下：

```
	while(*str) {
        int d = *str;
        if(d >= '0' && d<='9') {
            result *= 10;
            result += d - '0';
            if(result >= INT_MAX || result <= INT_MIN) {
                goto end;
            }
        } else {
            break;
        }
        str ++;
    }
```

还是不行。

```
-+1 还有这种测试用例。
```

这里改一下就好了。

```
if(*str == '-') {
        sign = 1;
        str ++;
    } else if(*str == '+') {
        str ++;
    }
```

```
Runtime: 4 ms, faster than 100.00% of C online submissions for String to Integer (atoi).
Memory Usage: 6.6 MB, less than 100.00% of C online submissions for String to Integer (atoi).
```

这是第一道我自己写的效果还不错的。



试了一下Python版本，报了超时，还有这种情况，第一次碰到。是因为我的有死循环导致的。

其他没有发现很好的。基本都是这个思路。

# C语言

自己写的。



# C++

NA



# java

NA



# python



# js

NA

