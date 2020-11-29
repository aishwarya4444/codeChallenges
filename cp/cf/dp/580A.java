import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int prev, curr, len=1, maxLen=1;
        int n, N = sc.nextInt();

        curr = sc.nextInt();
        for(n=2; n<=N; n++) {
            prev = curr;
            curr = sc.nextInt();
            if(prev <= curr) {
                len++;
            } else {
                len = 1;
            }
            maxLen = Math.max(len, maxLen);
        }

        System.out.println(maxLen);
    }
}