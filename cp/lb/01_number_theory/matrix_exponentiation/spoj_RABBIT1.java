/*
* https://www.spoj.com/problems/RABBIT1/
* RABBIT1 - Counting Rabbits
* */

/*
* Day          0 1 2 3 4 5
* Rabbits      1 1 2 3 5 8
* */

import java.util.*;
import java.lang.*;

class Main
{
    static int k = 2;
    static long mod = 0;

    static long[][] mul(long[][] m1, long[][] m2) {
        long[][] m3 = new long[k][k];
        int a, b, c;

        for(a=0; a<k; a++) {
            for(b=0; b<k; b++) {
                for(c=0; c<k; c++) {
                    m3[a][b] = (m3[a][b] + (m1[a][c]*m2[c][b])%mod ) % mod;
                }
            }
        }

        return m3;
    }

    static long[][] pow(long[][] m, int p) {
        if(p == 1) {
            return m;
        }

        if(p%2 == 1) {
            return mul(m, pow(m, p-1));
        }

        long[][] x = pow(m, p/2);
        return mul(x, x);
    }

    static long fib(int n) {
        int[] f = {1, 1};
        long[][] t = {{1, 1}, {1, 0}};

        if(n < 2) {
            return 1;
        }

        t = pow(t, n-1);

        return ( (t[0][0]*f[0])%mod + (t[0][1]*f[1])%mod ) % mod;
    }

    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);
        int n, T = sc.nextInt();

        while(T-- > 0) {
            n = sc.nextInt();
            mod = (long)Math.pow(2, sc.nextInt());

            System.out.println( fib(n) );
        }
    }
}