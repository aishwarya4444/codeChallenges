class CircularArrayLoop {
    private static int skip(int pos, boolean startPositive, int[] nums) {
        boolean currPositive = nums[pos]>=0;
        int next;

        if(currPositive != startPositive) {
            return -1;
        }

        next = pos + nums[pos];
        while(next<0 || next>=nums.length) {
            next = (next + nums.length) % nums.length;
        }

        if(next==pos) {
            return -1;
        }

        return next;
    }

    public static boolean loopExists(int[] nums) {
        // TODO: Write your code here
        boolean startPositive;
        int slow, fast;

        for(int i=0; i<nums.length; i++) {
            startPositive = nums[i]>=0;
            slow = i;
            fast = i;

            while(slow!=-1 && fast!=-1) {
                slow = skip(slow, startPositive, nums);
                fast = skip(fast, startPositive, nums);
                if(fast!=-1) {
                    fast = skip(fast, startPositive, nums);
                }
                if(slow==fast && slow!=-1) {
                    return true;
                }
            }
        }

        return false;
    }

    public static void main(String[] args) {
        System.out.println(CircularArrayLoop.loopExists(new int[] { 1, 2, -1, 2, 2 }));
        System.out.println(CircularArrayLoop.loopExists(new int[] { 2, 2, -1, 2 }));
        System.out.println(CircularArrayLoop.loopExists(new int[] { 2, 1, -1, -2 }));
    }
}

/*
https://leetcode.com/problems/circular-array-loop/
class Solution {
    boolean startPositive;

    private int skip(int pos, int[] nums) {
        boolean currPositive = nums[pos]>=0;
        int next;

        if(currPositive != startPositive) {
            return -1;
        }

        next = pos + nums[pos];
        while(next<0 || next>=nums.length) {
            next = (next + nums.length) % nums.length;
        }

        if(next==pos) {
            return -1;
        }

        return next;
    }

    public boolean circularArrayLoop(int[] nums) {
        int slow, fast;

        for(int i=0; i<nums.length; i++) {
            startPositive = nums[i]>=0;
            slow = i;
            fast = i;

            while(slow!=-1 && fast!=-1) {
                slow = skip(slow, nums);
                fast = skip(fast, nums);
                if(fast!=-1) {
                    fast = skip(fast, nums);
                }
                if(slow==fast && slow!=-1) {
                    return true;
                }
            }
        }

        return false;

    }
}
*/