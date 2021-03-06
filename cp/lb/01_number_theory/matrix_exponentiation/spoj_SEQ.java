/*
* SEQ - Recursive Sequence
* https://www.spoj.com/problems/SEQ/
* */
import java.util.*;
import java.lang.*;

class Main
{
    static long MOD = 1000000000;
    static int k = 0;

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

    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);
        int l, L = sc.nextInt();
        int r, c, n;
        long res;

        for(l=1; l<=L; l++) {
            k = sc.nextInt();
            long[][] t = new long[k][k];
            long[] f = new long[k];

            for(c=0; c<k; c++) {
                f[c] = sc.nextLong();
            }

            for(c=1; c<k; c++) {
                r = c-1;
                t[r][c] = 1;
            }

            for(r=k-1, c=k-1; c>=0; c--) {
                t[r][c] = sc.nextLong();
            }

            n = sc.nextInt();

            res = 0;
            if(n <= k) {
                res = f[n-1];
            } else {
                long[][] _t = pow(t, n-1);
                for(c=0; c<k; c++) {
                    res = ( res%MOD + (_t[0][c]*f[c])%MOD )%MOD;
                }
            }

            System.out.println(res);
        }
    }
}