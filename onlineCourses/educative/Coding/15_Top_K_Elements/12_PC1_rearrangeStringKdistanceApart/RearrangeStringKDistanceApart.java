import java.util.*;

class RearrangeStringKDistanceApart {

    public static String reorganizeString(String str, int k) {
        // TODO: Write your code here
        if(k<=1) {
            return str;
        }
        StringBuilder result = new StringBuilder(str.length());
        Map<Character, Integer> freq = new HashMap<>();
        Queue<Map.Entry<Character, Integer>> seq = new LinkedList<>();
        PriorityQueue<Map.Entry<Character, Integer>> maxHeap = new PriorityQueue<Map.Entry<Character, Integer>>((e1, e2) -> {
            return e2.getValue()-e1.getValue();
        });

        for(char ch: str.toCharArray()) {
            freq.put(ch, freq.getOrDefault(ch, 0)+1);
        }

        maxHeap.addAll(freq.entrySet());

        while(maxHeap.size() > 0) {
            Map.Entry<Character, Integer> entry = maxHeap.poll();
            result.append(entry.getKey());
            seq.add(entry);
            if(seq.size() == k) {
                entry = seq.poll();
                if(entry.getValue() > 1) {
                    entry.setValue(entry.getValue()-1);
                    maxHeap.add(entry);
                }
            }
        }
        return result.length() == str.length() ? result.toString() : "";
    }

    public static void main(String[] args) {
        System.out.println("Reorganized string: " +
                RearrangeStringKDistanceApart.reorganizeString("mmpp", 2));
        System.out.println("Reorganized string: " +
                RearrangeStringKDistanceApart.reorganizeString("Programming", 3));
        System.out.println("Reorganized string: " +
                RearrangeStringKDistanceApart.reorganizeString("aab", 2));
        System.out.println("Reorganized string: " +
                RearrangeStringKDistanceApart.reorganizeString("aappa", 3));
    }
}
