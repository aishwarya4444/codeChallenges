import java.lang.Math;

class CalculateComplement {
    public static int bitwiseComplement(int n) {
        // TODO: Write your code here
        int mask=1;
        while(mask < n) {
            mask = (mask<<1) | 1;
        }

        return n ^ mask;
    }

    public static void main( String args[] ) {
        System.out.println("Bitwise complement is: " + CalculateComplement.bitwiseComplement(8));
        System.out.println("Bitwise complement is: " + CalculateComplement.bitwiseComplement(10));
    }
}