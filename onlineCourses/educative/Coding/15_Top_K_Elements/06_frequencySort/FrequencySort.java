import java.util.*;

class FrequencySort {

    public static String sortCharacterByFrequency(String str) {
        // TODO: Write your code here
        StringBuilder result = new StringBuilder(str.length());
        Map<Character, Integer> freq = new HashMap<>();
        PriorityQueue<Map.Entry<Character, Integer>> maxHeap = new PriorityQueue<Map.Entry<Character, Integer>>((e1, e2) -> e2.getValue()-e1.getValue());

        for(char ch: str.toCharArray()) {
            freq.put(ch, freq.getOrDefault(ch, 0) + 1);
        }

        for(Map.Entry<Character, Integer> entry: freq.entrySet()) {
            maxHeap.add(entry);
        }
        // maxHeap.addAll(freq.entrySet());

        while(maxHeap.size() > 0) {
            char ch = maxHeap.peek().getKey();
            Integer count = maxHeap.peek().getValue();
            while(count > 0) {
                result.append(ch);
                count--;
            }
            maxHeap.poll();
        }

        return result.toString();
    }

    public static void main(String[] args) {
        String result = FrequencySort.sortCharacterByFrequency("Programming");
        System.out.println("Here is the given string after sorting characters by frequency: " + result);

        result = FrequencySort.sortCharacterByFrequency("abcbab");
        System.out.println("Here is the given string after sorting characters by frequency: " + result);
    }
}
