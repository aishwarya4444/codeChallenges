class CyclicSort {

    public static void sort(int[] nums) {
        // TODO: Write your code here
        int i=0, j, N=nums.length, tmp;

        while(i<N) {
            j = nums[i]-1;
            if(j>=0 && nums[i]!=nums[j]) {
                // swap(nums[i], nums[j]);
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            } else {
                i++;
            }
        }
    }
}
