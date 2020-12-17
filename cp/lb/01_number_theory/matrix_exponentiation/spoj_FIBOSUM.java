/*
 * FIBOSUM - Fibonacci Sum
 * https://www.spoj.com/problems/FIBOSUM/
 * */
import java.util.*;
import java.lang.*;

class Main
{
    static long MOD = 1000000007;
    static int k = 2;

    static long[][] multiply(long[][] m1, long[][] m2) {
        int a, b, c;
        long[][] m3 = new long[k][k];

        for(a=0; a<k; a++) {
            for(b=0; b<k; b++) {
                for(c=0; c<k; c++) {
                    m3[a][b] = ( m3[a][b]%MOD + (m1[a][c]*m2[c][b])%MOD )%MOD;
                }
            }
        }

        return m3;
    }

    static long[][] pow(long[][] m, int n) {
        if(n == 1) {
            return m;
        }

        if(n%2 == 1) {
            return multiply(m, pow(m, n-1));
        }

        long[][] x = pow(m, n/2);
        return multiply(x, x);
    }

    static long fib(int n) {
        long[][] t = {{0, 1}, {1, 1}};
        long[] f = {0, 1};

        if(n <= k) {
            return f[n-1];
        }
        long[][] _t = pow(t, n-1);
        return _t[0][1];
    }

    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);
        int l, L = sc.nextInt();
        int m, n;
        long res;

        for(l=1; l<=L; l++) {

            n = 1+sc.nextInt();
            m = 1+sc.nextInt();

            res = (MOD + fib(m+2) - fib(n+1)) % MOD;

            System.out.println(res);
        }
    }
}