// assingment: find indexes of 2 numbers from input array,
// that summed together equal the target number.
// e.g {1,2,3,4} and target 6, 
// return indexes {1, 3} which is numbers 2 and 4

import java.util.HashMap;
import java.util.Arrays;

public class TwoSum {

    public static void main(String[] args) {
        int[] testArray = { 1, 2, 3, 4 };
        int target = 6;

        int[] answer = twoSum(testArray, target);
        System.out.println(Arrays.toString(answer));
    }

    public static int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int[] answer = { 0, 1 };
        for (int i = 0; i < nums.length; i++) {
            System.out.println(target - nums[i]);
            boolean matchingNumberExists = map.containsKey(target - nums[i]);
            if (matchingNumberExists) {
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