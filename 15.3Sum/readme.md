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



# C语言

NA



# C++

NA



# java

NA



# python

NA

# js

NA

