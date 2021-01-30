import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
};

class LevelAverage {
    public static List<Double> findLevelAverages(TreeNode root) {
        List<Double> result = new ArrayList<>();
        // TODO: Write your code here
        Queue<TreeNode> q = new LinkedList<>();
        Double sum;
        int n, N;

        if(root != null) {
            q.add(root);
        }

        while(!q.isEmpty()) {
            N = q.size();
            sum = 0.0;

            for(n=0; n<N; n++) {
                root = q.poll();
                sum += root.val;
                if(root.left != null) {
                    q.add(root.left);
                }
                if(root.right != null) {
                    q.add(root.right);
                }
            }
            result.add(sum/N);
        }
        return result;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(12);
        root.left = new TreeNode(7);
        root.right = new TreeNode(1);
        root.left.left = new TreeNode(9);
        root.left.right = new TreeNode(2);
        root.right.left = new TreeNode(10);
        root.right.right = new TreeNode(5);
        List<Double> result = LevelAverage.findLevelAverages(root);
        System.out.print("Level averages are: " + result);
    }
}

/*
https://leetcode.com/problems/average-of-levels-in-binary-tree/
class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> result = new ArrayList<Double>();
        Double total;
        int n, N;
        Queue<TreeNode> q = new LinkedList<TreeNode>();

        if(root!=null) {
            q.add(root);
        }

        while(q.size() > 0) {
            N = q.size();
            total = 0.0;
            for(n=0; n<N; n++) {
                root = q.poll();
                total += root.val;
                if(root.left!=null) {
                    q.add(root.left);
                }
                if(root.right!=null) {
                    q.add(root.right);
                }
            }
            total /= N;
            result.add(total);
        }

        return result;
    }
}
 */