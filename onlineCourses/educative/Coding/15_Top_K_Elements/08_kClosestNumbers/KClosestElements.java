import java.util.*;

class Entry {
    int key;
    int value;

    public Entry(int key, int value) {
        this.key = key;
        this.value = value;
    }
}

class KClosestElements {

    public static List<Integer> findClosestElements(int[] arr, int K, Integer X) {
        List<Integer> result = new ArrayList<>();
        // TODO: Write your code here
        PriorityQueue<Entry> maxHeap = new PriorityQueue<Entry>((e1, e2) -> e2.value - e1.value);

        for(int num: arr) {
            maxHeap.add(new Entry(num, Math.abs(num-X)));
            if(maxHeap.size() > K) {
                maxHeap.poll();
            }
        }

        while(maxHeap.size() > 0) {
            result.add(maxHeap.poll().key);
        }
        return result;
    }

    public static void main(String[] args) {
        List<Integer> result = KClosestElements.findClosestElements(new int[] { 5, 6, 7, 8, 9 }, 3, 7);
        System.out.println("'K' closest numbers to 'X' are: " + result);

        result = KClosestElements.findClosestElements(new int[] { 2, 4, 5, 6, 9 }, 3, 6);
        System.out.println("'K' closest numbers to 'X' are: " + result);

        result = KClosestElements.findClosestElements(new int[] { 2, 4, 5, 6, 9 }, 3, 10);
        System.out.println("'K' closest numbers to 'X' are: " + result);
    }
}
