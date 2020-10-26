import java.util.*;

class FindAllDuplicate {

    public static List<Integer> findNumbers(int[] nums) {
        List<Integer> duplicateNumbers = new ArrayList<>();
        // TODO: Write your code here
        int i=0, j, tmp;

        while(i<nums.length) {
            j = nums[i]-1;
            if(j>=0 && j<nums.length && nums[i]!=nums[j]) {
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            } else {
                i++;
            }
        }

        for(i=0; i<nums.length; i++) {
            if(i+1 != nums[i]) {
                duplicateNumbers.add(nums[i]);
            }
        }
        return duplicateNumbers;
    }
}
