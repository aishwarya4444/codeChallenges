import java.util.*;

class RearrangeString {

    public static String rearrangeString(String str) {
        // TODO: Write your code here
        StringBuilder result = new StringBuilder(str.length());
        Map<Character, Integer> freq = new HashMap<>();
        PriorityQueue<Map.Entry<Character, Integer>> maxHeap = new PriorityQueue<Map.Entry<Character, Integer>>((e1, e2) -> {
            return e2.getValue()-e1.getValue();
        });
        Queue<Map.Entry<Character, Integer>> seq = new LinkedList<>();

        for(char ch: str.toCharArray()) {
            freq.put(ch, freq.getOrDefault(ch, 0)+1);
        }

        maxHeap.addAll(freq.entrySet());

        while(maxHeap.size() > 0) {
            Map.Entry<Character, Integer> entry = maxHeap.poll();
            result.append(entry.getKey());
            seq.add(entry);
            if(seq.size() == 2) {
                entry = seq.poll();
                if (entry.getValue() > 1) {
                    entry.setValue(entry.getValue() - 1);
                    maxHeap.add(entry);
                }
            }
        }
        return result.toString();
    }

    public static void main(String[] args) {
        System.out.println("Rearranged string: " + RearrangeString.rearrangeString("aappp"));
        System.out.println("Rearranged string: " + RearrangeString.rearrangeString("Programming"));
        System.out.println("Rearranged string: " + RearrangeString.rearrangeString("aapa"));
    }
}
