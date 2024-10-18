import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int[] answer = { 0, 1 };
        for (int i = 0; i < nums.length; i++) {
            System.out.println(target - nums[i]);
            boolean matchingNumberPairExists = map.containsKey(target - nums[i]);
            if (matchingNumberPairExists) {
                answer[0] = map.get(target - nums[i]);
                answer[1] = i;
                return answer;
            }
            if (map.containsKey(nums[i]) == false) {
                map.put(nums[i], i);
            }

        }
        return answer;
    }
}