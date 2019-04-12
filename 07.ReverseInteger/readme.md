# 分析

我先自己实现一个版本；

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reverse(int x) {
	char buf[32] = {0};
	char out[32] = {0};
	int sign = 0;
	if(x < 0) {
		x = -x;
		sign = 1;
	}
	sprintf(buf, "%d", x);
	int i;
	int len = strlen(buf);
	for(i=0; i<len;i++ ) {
		out[i] = buf[len-i-1];
	}
	int result;
	result = atoi(out);
    if(sign) {
        result = -result;
    }
	return result;
}
```

出错了。无法处理最边沿的那个负数。

```
 runtime error: negation of -2147483648 cannot be represented in type 'int'; 
 cast to an unsigned type to negate this value to itself 
```

对负数取负数的方法，行不通。

改了。

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reverse(int x) {
	char buf[32] = {0};
	char out[32] = {0};
	sprintf(buf, "%d", x);
	int i = 0;
	int len = strlen(buf);
    int sign = 0;
    if(x < 0) {
        out[0] = '-';
        sign = 1;
    }
    if(sign) {
        for(; i<len;i++ ) {
            out[i+1] = buf[len-i-1];
        }
    } else {
        for(; i<len;i++ ) {
            out[i] = buf[len-i-1];
        }
    }

	int result;
	result = atoi(out);

	return result;
}
```

还是不行，说是1534236469这个测试用例，预期输出是0，为什么是0？

字符串的方式，是非常笨的方式。放弃。

直接从整数上入手。

```
int reverse(int x) {
	long result = 0;
    while(x != 0) {
        result *= 10;
        result += x%10;
        x = x/10;
        if(result > INT_MAX || result < INT_MIN) {
            result = 0;
        }
    }
    return result;
}
```

这么简单就可以解决了。

其实，用字符串的方式，也是可以的。

只是我没有仔细看题目。

```
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
```

题目里写了。

在溢出的时候，返回0就好了。

所以用long来存数据，发现大于INT_MAX或者小于INT_MIN的时候。

另外，atoi函数，“321-”，这个负号可以不管，会被自动去掉的。

如果是c++，是std::reverse函数就可以很好地进行翻转字符串。



# C语言





# C++





# java

NA



# python

NA

# js

NA

