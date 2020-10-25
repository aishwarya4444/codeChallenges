import java.util.*;

class TaskScheduler {

    public static int scheduleTasks(char[] tasks, int k) {
        // TODO: Write your code here
        PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>((e1, e2) -> {
            return e2-e1;
        });
        Queue<Integer> seq = new LinkedList<>();
        Map<Character, Integer> freq = new HashMap<>();
        int time, count, total=0;

        for(char task: tasks) {
            freq.put(task, freq.getOrDefault(task, 0)+1);
        }

        for(Map.Entry<Character, Integer> entry: freq.entrySet()) {
            maxHeap.add(entry.getValue());
        }

        while(maxHeap.size() > 0) {
            for(time=0; time<=k && maxHeap.size()>0; time++) {
                count = maxHeap.poll();
                count--;
                if(count > 0) {
                    seq.add(count);
                }
            }

            if(seq.size() > 0) {
                total += k+1;
                while(seq.size() > 0) {
                    maxHeap.add(seq.poll());
                }
            } else {
                total += time;
            }
        }
        return total;
    }

    public static void main(String[] args) {
        char[] tasks = new char[] { 'a', 'a', 'a', 'b', 'c', 'c' };
        System.out.println("Minimum intervals needed to execute all tasks: " + TaskScheduler.scheduleTasks(tasks, 2));

        tasks = new char[] { 'a', 'b', 'a' };
        System.out.println("Minimum intervals needed to execute all tasks: " + TaskScheduler.scheduleTasks(tasks, 3));
    }
}
