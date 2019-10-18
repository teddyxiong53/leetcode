# 分析

C语言版本很不好写。

用c++来写。

就算是暴力法。也碰到一些问题。

排序放入，剔除相同项。

```
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::vector;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i,j,k;
        int sz = nums.size();
        vector<vector<int>> result;
        if(sz < 3) {
            return result;
        }

        int flag = 1;
        for(i=0; i<sz-2; i++) {
            for(j=i+1; j<sz-1; j++) {
                for(k=j+1; k<sz; k++) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> v;


                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        std::sort(v.begin(), v.end());
                        if(flag) {
                            result.push_back(v);
                            flag = 0;
                        }
                        int found = 0;
                        for(auto it : result) {
                            if(it == v) {
                                //printf("already in the vector\n");
                                //result.pop_back();
                                found = 1;
                                break;
                            }
                        }
                        if(!found) {
                            result.push_back(v);
                        }

                    }
                }
            }
        }
        //check same combination

        return result;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums = {-7,-10,-1,3,0,-7,-9,-1,10,8,-6,4,14,-8,9,-15,0,-4,-5,9,11,3,-5,-8,2,-6,-14,7,-14,10,5,-6,7,11,4,-7,11,11,7,7,-4,-14,-12,-13,-14,4,-13,1,-15,-2,-12,11,-14,-2,10,3,-1,11,-5,1,-2,7,2,-10,-5,-8,-10,14,10,13,-2,-9,6,-7,-7,7,12,-5,-14,4,0,-11,-8,2,-6,-13,12,0,5,-15,8,-12,-1,-4,-15,2,-5,-9,-7,12,11,6,10,-6,14,-12,9,3,-10,10,-8,-2,6,-9,7,7,-7,4,-8,5,-4,8,0,3,11,0,-10,-9};
    vector<vector<int>> result = s->threeSum(nums);

    printf("ok\n");
}
```

这个执行是不会出错的。但是报了超时。

估计效率太低了。

看结果跟默认结果略有区别。



这个的符合规定的解法是怎样的呢？

discuss区里找到一个python解法。

关键点有这些：

```
1、先对nums进行排序。排序这个很关键。
2、然后固定一个值，一个从前面取，一个从后面取，如果大于0，则后面那个往前一步。如果小于0，则前面那个往后一步。等于0，则把当前的添加到结果里。
```

另外，使用set也可以，最后再list(result)来转一下就好了。

用这种算法后，速度很快，不到一秒就完成了。

从提交结果看，这个算法也只是比18%的python解决方法快。只是内存占用比较少。

使用c++的话，耗时只有88ms，比起1s的python，要快进10倍。



# C语言

NA



# C++

注意这个的去掉重复项的方法。

```
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i=0; i<n; i++) {
            int target = -nums[i];
            int l = i+1;
            int r = n-1;
            while(l < r) {
                int sum = nums[l] + nums[r];
                if(sum > target) {
                    r--;
                } else if(sum < target) {
                    l++;
                } else {
                    res.push_back({nums[l], nums[i], nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l] == res.back()[1]) {
                        l++;
                    }
                    while(l < r&& nums[r] == res.back()[2]) {
                        r--;
                    }
                }
            }
            while(i+1 < n && nums[i] == nums[i+1]) {
                i++;
            }
        }
        return res;
    }
};
```





# java

NA



# python

最直观的写法。

```
class Solution:
    def threeSum(self, nums):
        sz = len(nums)
        result = list()
        for i in range(0, sz):
            for j in range(i+1, sz):
                for k in range(j+1, sz):
                    if nums[i] + nums[j] + nums[k] == 0:
                        tmp = [nums[i], nums[j], nums[k]]
                        result.append(tmp)
        return result
```

当前这样是有问题的。

```

[[-1,0,1],[-1,2,-1],[0,1,-1]]
```

有重复项。

怎么去掉这种重复项呢？

对里面的内容进行排序就好了。

```
tmp.sort()
```

现在还是超时。对应的用例长度是3000个数字。

我在本地运行一下，统计运行时间。

```
class Solution:
    def threeSum(self, nums):
        nums.sort()
        result = set()
        sz = len(nums)
        for i in range(0, sz):
            l = i + 1
            r = sz -1
            target = 0 - nums[i]
            while l < r:
                if nums[l] + nums[r] == target:
                    result.add((nums[i], nums[l], nums[r]))
                    l += 1
                    r -= 1
                elif nums[l] + nums[r] < target:
                    l+=1
                else:
                    r -= 1
        return list(result)
```







# js

NA

