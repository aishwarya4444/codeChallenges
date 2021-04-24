import java.util.*;

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class Program {
  static class MinHeap {
    List<Integer> heap = new ArrayList<Integer>();

    public MinHeap(List<Integer> array) {
      heap = buildHeap(array);
    }

    public List<Integer> buildHeap(List<Integer> array) {
      // Write your code here.
      int N = array.size();
      for(int i=N/2-1; i>=0; i--) {
        siftDown(i, N-1, array);
      }
      return array;
    }

    public void siftDown(int currentIdx, int endIdx, List<Integer> heap) {
      // Write your code here.
      int minIdx = currentIdx, leftIdx = 2*currentIdx+1, rightIdx = 2*currentIdx+2;

      if(leftIdx <= endIdx && heap.get(minIdx) > heap.get(leftIdx)) {
        minIdx = leftIdx;
      }

      if(rightIdx <= endIdx && heap.get(minIdx) > heap.get(rightIdx)) {
        minIdx = rightIdx;
      }

      if(minIdx != currentIdx) {
        swap(minIdx, currentIdx, heap);
        siftDown(minIdx, endIdx, heap);
      }
    }

    public void siftUp(int currentIdx, List<Integer> heap) {
      // Write your code here.
      int parentIdx = (currentIdx-1)/2;
      while(currentIdx > 0 && heap.get(currentIdx) < heap.get(parentIdx)) {
        swap(currentIdx, parentIdx, heap);
        currentIdx = parentIdx;
        parentIdx = (currentIdx-1)/2;
      }
    }

    public int peek() {
      // Write your code here.
      return heap.get(0);
    }

    public int remove() {
      // Write your code here.
      int N = heap.size(), val = heap.get(0);
      swap(0, N-1, heap);
      heap.remove(N-1);
      siftDown(0, N-2, heap);
      return val;
    }

    public void insert(int value) {
      // Write your code here.
      int N = heap.size();
      heap.add(value);
      siftUp(N, heap);
    }

    public void swap(int i, int j, List<Integer> array) {
      int tmp = array.get(i);
      array.set(i, array.get(j));
      array.set(j, tmp);
    }
  }
}
