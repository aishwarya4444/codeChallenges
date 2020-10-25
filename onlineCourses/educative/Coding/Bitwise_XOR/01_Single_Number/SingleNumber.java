class SingleNumber {
    public static int findSingleNumber(int[] arr) {
        // TODO: Write your code here
        int result=0;
        for(int num: arr) {
            result ^= num;
        }
        return result;
    }

    public static void main( String args[] ) {
        System.out.println(findSingleNumber(new int[]{1, 4, 2, 1, 3, 2, 3}));
    }
}