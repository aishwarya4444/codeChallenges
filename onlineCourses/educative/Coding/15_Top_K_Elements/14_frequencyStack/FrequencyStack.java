import java.util.*;

class Node {
    public int num;
    public int count;
    public int seq;
    public Node(int num, int count, int seq) {
        this.num = num;
        this.count = count;
        this.seq = seq;
    }
}

class FrequencyStack {
    int seq = 0;
    PriorityQueue<Node> maxHeap = new PriorityQueue<Node>((n1, n2) -> {
        if(n1.seq != n2.seq) {
            return n2.count-n1.count;
        } else {
            return n2.seq-n1.seq;
        }
    });
    Map<Integer, Integer> freq = new HashMap<>();

    public void push(int num) {
        // TODO: Write your code here
        freq.put(num, freq.getOrDefault(num, 0)+1);
        maxHeap.add(new Node(num, freq.get(num), seq++));
    }

    public int pop() {
        // TODO: Write your code here
        int num = -1;
        if(maxHeap.size() > 0) {
            num = maxHeap.poll().num;
            freq.put(num, freq.get(num)-1);
            if(freq.get(num) == 0) {
                freq.remove(num);
            }
        }
        return num;
    }

    public static void main(String[] args) {
        FrequencyStack frequencyStack = new FrequencyStack();
        frequencyStack.push(1);
        frequencyStack.push(2);
        frequencyStack.push(3);
        frequencyStack.push(2);
        frequencyStack.push(1);
        frequencyStack.push(2);
        frequencyStack.push(5);
        System.out.println(frequencyStack.pop());
        System.out.println(frequencyStack.pop());
        System.out.println(frequencyStack.pop());
    }
}
