/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class GFG {
    public static void fact(int num) {
        int n;
        BigInteger prod = new BigInteger("1");

        for(n=2; n<=num; n++) {
            prod = prod.multiply(BigInteger.valueOf(n));
        }

        System.out.println(prod);
    }

    public static void main (String[] args) {
        //code
        Scanner sc = new Scanner(System.in);
        int n, N=sc.nextInt();

        for(n=1; n<=N; n++) {
            GFG.fact(sc.nextInt());
        }
    }
}