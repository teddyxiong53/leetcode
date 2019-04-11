import java.util.Map;
import java.util.HashMap;
import java.lang.Integer;
import java.util.Arrays;

public class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int i=0; i<nums.length; i++) {
            int complement = target - nums[i];
            if(map.containsKey(complement)) {
                return new int[]{map.get(complement), i};
            }
            map.put(nums[i], i);
        }
        return new int[]{-1,-1};
    }
    public static void main(String[] args) {
        int[] nums = {2,7,11,15};
        Solution s = new Solution();
        System.out.println(Arrays.toString(s.twoSum(nums, 9)));

    }
}