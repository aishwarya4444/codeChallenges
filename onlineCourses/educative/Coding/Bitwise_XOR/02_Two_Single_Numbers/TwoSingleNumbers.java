class TwoSingleNumbers {

    public static int[] findSingleNumbers(int[] nums) {
        // TODO: Write your code here
        int num1=0, num2=0, xor=0, set=1;

        for(int num: nums) {
            xor ^= num;
        }

        while((set & xor) == 0) {
            set = set << 1;
        }

        for(int num: nums) {
            if((num & set) == 0) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
        return new int[] { num1, num2 };
    }

    public static void main(String[] args) {
        int[] arr = new int[] { 1, 4, 2, 1, 3, 5, 6, 2, 3, 5 };
        int[] result = TwoSingleNumbers.findSingleNumbers(arr);
        System.out.println("Single numbers are: " + result[0] + ", " + result[1]);

        arr = new int[] { 2, 1, 3, 2 };
        result = TwoSingleNumbers.findSingleNumbers(arr);
        System.out.println("Single numbers are: " + result[0] + ", " + result[1]);
    }
}
