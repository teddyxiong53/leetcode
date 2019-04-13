# 分析

这个题目开始看有点费解。

本质含义是，两条竖线之间形成的矩形的面积，面积除了跟竖线高度有关系，跟竖线之间的举例也有关系。

```
int maxArea(int* height, int heightSize) {
    int i,j;
    long long  area, h,w;
    int max = 0;
    for(i=0; i<heightSize-1; i++) {
        for(j=1; j<heightSize; j++) {
            w = j-i;
            if(height[j] > height[i]) {
                h = height[i];
            } else {
                h = height[j];
            }
            area = w*h;
            if(area > max) {
                max = area;
            }
        }
    }
    return max;
}
```

我用这个暴力解法。

总是报Time Limit Exceeded。

计算是可以算出来的。就是时间长了点。

是一个地方有问题。

```
for(j=1; j<heightSize; j++) {
这里改成
for(j=i+1; j<heightSize; j++) {
```



除了暴力法，可以怎么提高效率呢？

都是从问题本身去分析的。

算法是：从距离最远的两根线开始开始看。

哪个比对方小，哪个就往中间挪动。

```
int maxArea(int* height, int heightSize) {
    int i,j;
    long long area;
    int h1, h2;
    int w, h;
    int max = 0;
    int i_prev = heightSize-1;
    int i_next = 0;
    while(i_prev - i_next >= 1) {
        h1 = height[i_next];
        h2 = height[i_prev];
        w = i_prev - i_next;
        if(h1<h2) {
            h = h1;
            i_next ++;
        } else {
            i_prev --;
            h = h2;
        }
        area = w*h;
        if(area > max) {
            max = area;
        }
    }
    return max;
}
```

这个效率可以。只需要一次循环。



# C语言

暴力法和一次循环法。





# C++

这个主要看思路，各种用法。





# java

NA



# python

NA

# js

NA

