class HappyNumber {

    private static int findSum(int num) {
        int sum = 0, digit;

        while(num != 0) {
            sum += Math.pow(num%10, 2);
            num /= 10;
        }

        return sum;
    }

    public static boolean find(int num) {
        // TODO: Write your code here
        int slow = num;
        int fast = num;

        do {
            slow = findSum(slow);
            fast = findSum(findSum(fast));
        } while(slow!=fast);

        return slow==1;
    }

    public static void main(String[] args) {
        System.out.println(HappyNumber.find(23));
        System.out.println(HappyNumber.find(12));
    }
}
