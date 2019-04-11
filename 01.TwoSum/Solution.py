class Solution:
    def twoSum(self, nums, target):
        dic = {}
        for index, num in enumerate(nums):
            if num in dic:
                return [dic[num], index]
            dic[target-num] = index;
        return dic

nums = [2,7 ,11, 15]
print Solution().twoSum(nums, 9)