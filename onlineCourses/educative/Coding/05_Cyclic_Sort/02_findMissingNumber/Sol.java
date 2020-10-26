class MissingNumber {

    public static int findMissingNumber(int[] nums) {
        // TODO: Write your code here
        int i, j, tmp;

        for(i=0; i<nums.length; ) {
            j = nums[i];
            if(j>=0 && j<nums.length && nums[i]!=nums[j]) {
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            } else {
                i++;
            }
        }

        for(i=0; i<nums.length; i++) {
            if(i!=nums[i]) {
                return i;
            }
        }
        return i;
    }
}
