class Solution {
    public static int[][] flipAndInvertImage(int[][] arr) {
        //TODO: Write your code here
        int r, c1, c2, R=arr.length, C=arr[0].length;
        int num1, num2;

        for(r=0; r<R; r++) {
            c1=0;
            c2=C-1;
            while(c1<=c2) {
                num1 = arr[r][c1]^1;
                num2 = arr[r][c2]^1;

                arr[r][c1] = num2;
                arr[r][c2] = num1;

                c1++;
                c2--;
            }
        }
        return arr;
    }

    public static void print(int[][] arr) {
        for(int i=0; i < arr.length; i++) {
            for (int j=0; j < arr[i].length; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[][] arr = {{1, 0, 1}, {1, 1, 1}, {0, 1, 1}};
        print(flipAndInvertImage(arr));

        int[][]arr2 = {{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
        print(flipAndInvertImage(arr2));
    }
}