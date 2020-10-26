import java.util.*;

class FirstKMissingPositive {

    public static List<Integer> findNumbers(int[] nums, int k) {
        List<Integer> missingNumbers = new ArrayList<>();
        // TODO: Write your code here
        Set<Integer> present = new HashSet<>();
        int i, j, tempNum;
        for(i=0; i<nums.length; ) {
            j = nums[i]-1;
            if(j>=0 && j<nums.length && nums[i]!=nums[j]) {
                tempNum = nums[i];
                nums[i] = nums[j];
                nums[j] = tempNum;
            } else {
                i++;
            }
        }

        for(i=0; i<nums.length && missingNumbers.size()<k; i++) {
            if(i+1 != nums[i]) {
                missingNumbers.add(i+1);
                present.add(nums[i]);
            }
        }

        for(; missingNumbers.size()<k; i++) {
            if(!present.contains(i+1)) {
                missingNumbers.add(i+1);
            }
        }

        return missingNumbers;
    }
}