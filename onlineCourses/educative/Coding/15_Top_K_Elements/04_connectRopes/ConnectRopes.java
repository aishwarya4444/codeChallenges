import java.util.*;

class ConnectRopes {

    public static int minimumCostToConnectRopes(int[] ropeLengths) {
        // TODO: Write your code here
        PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>((l1, l2) -> l1 - l2);
        int i, l1, l2, total=0;

        for(i=0; i<ropeLengths.length; i++) {
            minHeap.add(ropeLengths[i]);
        }

        while(minHeap.size() > 1) {
            l1 = minHeap.poll();
            l2 = minHeap.poll();
            total = total + l1 + l2;
            minHeap.add(l1+l2);
        }
        return total;
    }

    public static void main(String[] args) {
        int result = ConnectRopes.minimumCostToConnectRopes(new int[] { 1, 3, 11, 5 });
        System.out.println("Minimum cost to connect ropes: " + result);
        result = ConnectRopes.minimumCostToConnectRopes(new int[] { 3, 4, 5, 6 });
        System.out.println("Minimum cost to connect ropes: " + result);
        result = ConnectRopes.minimumCostToConnectRopes(new int[] { 1, 3, 11, 5, 2 });
        System.out.println("Minimum cost to connect ropes: " + result);
    }
}
