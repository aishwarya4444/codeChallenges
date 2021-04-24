import java.util.*;

// Do not edit the class below except for the insertKeyValuePair,
// getValueFromKey, and getMostRecentKey methods. Feel free
// to add new properties and methods to the class.
class Program {
  static class LRUCache {
    int maxSize;

    Map<String, DLLnode> cache = new HashMap<String, DLLnode>();
    int currSize = 0;
    DLL recent = new DLL();

    public LRUCache(int maxSize) {
      this.maxSize = maxSize > 1 ? maxSize : 1;
    }

    public void insertKeyValuePair(String key, int value) {
      // Write your code here.
      if(!cache.containsKey(key)) {
        if(currSize == maxSize) {
          evictLeastRecent();
        } else {
          currSize++;
        }
        cache.put(key, new DLLnode(key, value));
      } else {
        replaceKey(key, value);
      }
      updateMostRecent(cache.get(key));
    }

    public LRUResult getValueFromKey(String key) {
      // Write your code here.
      if(!cache.containsKey(key)) {
        return new LRUResult(false, -1);
      }
      updateMostRecent(cache.get(key));
      return new LRUResult(true, cache.get(key).value);
    }

    public String getMostRecentKey() {
      // Write your code here.
      if(recent.head == null) {
        return "";
      }
      return recent.head.key;
    }

    public void evictLeastRecent() {
      String keyToRemove = recent.tail.key;
      recent.removeTail();
      cache.remove(keyToRemove);
    }

    public void updateMostRecent(DLLnode node) {
      recent.setHeadTo(node);
    }

    public void replaceKey(String key, int value) {
      if(!this.cache.containsKey(key)) {
        return;
      }
      cache.get(key).value = value;
    }
  }

  static class DLL {
    DLLnode head = null;
    DLLnode tail = null;

    public void setHeadTo(DLLnode node) {
      if(head == node) {
        return;
      } else if(head == null) {
        head = node;
        tail = node;
      } else if(head == tail) {
        tail.prev = node;
        head = node;
        head.next = tail;
      } else {
        if(tail == node) {
          removeTail();
        }
        node.removeBindings();
        head.prev = node;
        node.next = head;
        head = node;
      }
    }

    public void removeTail() {
      if(tail == null) {
        return;
      }
      if(tail == head) {
        head = null;
        tail = null;
        return;
      }
      tail = tail.prev;
      tail.next = null;
    }
  }

  static class DLLnode {
    String key;
    int value;
    DLLnode prev = null;
    DLLnode next = null;

    public DLLnode(String key, int value) {
      this.key = key;
      this.value = value;
    }

    public void removeBindings() {
      if(prev != null) {
        prev.next = next;
      }
      if(next != null) {
        next.prev = prev;
      }
      prev = null;
      next = null;
    }
  }

  static class LRUResult {
    boolean found;
    int value;

    public LRUResult(boolean found, int value) {
      this.found = found;
      this.value = value;
    }
  }
}
