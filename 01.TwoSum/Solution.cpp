#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> record;
        for(int i=0; i != nums.size(); i++) {
            auto found = record.find(nums[i]);
            if(found != record.end()) {
                return {found->second, i};
            }
            record.emplace(target-nums[i], i);
        }
        return {-1, -1};
    }

};

int main()
{
    Solution s;
    std::vector<int> nums = {2,7,11,15};
    std::vector<int> result = s.twoSum(nums, 9);
    for(std::vector<int>::iterator it=result.begin(); it != result.end(); it++) {
        std::cout << *it << std::endl;
    }
}