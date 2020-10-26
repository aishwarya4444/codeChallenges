class FindCorruptNums {

    public static int[] findNumbers(int[] nums) {
        // TODO: Write your code here
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

        for(i=0; i<nums.length; i++) {
            if(i+1 != nums[i]) {
                return new int[] {nums[i], i+1};
            }
        }
        return new int[] { -1, -1 };
    }
}
