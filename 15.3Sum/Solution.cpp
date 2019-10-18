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

