import java.util.*;

class Program {
  public static AncestralTree getYoungestCommonAncestor(
      AncestralTree topAncestor, AncestralTree descendantOne, AncestralTree descendantTwo) {
    // Write your code here.
    // O(d) time, O(n) space
    Set<AncestralTree> visited = new HashSet<>();

    while(descendantTwo != topAncestor) {
      visited.add(descendantTwo);
      descendantTwo = descendantTwo.ancestor;
    }

    while(descendantOne != topAncestor) {
      if(visited.contains(descendantOne)) {
        return descendantOne;
      }
      descendantOne = descendantOne.ancestor;
    }
    return topAncestor; // Replace this line
  }

  static class AncestralTree {
    public char name;
    public AncestralTree ancestor;

    AncestralTree(char name) {
      this.name = name;
      this.ancestor = null;
    }

    // This method is for testing only.
    void addAsAncestor(AncestralTree[] descendants) {
      for (AncestralTree descendant : descendants) {
        descendant.ancestor = this;
      }
    }
  }
}

/*
import java.util.*;

class Program {
  public static AncestralTree getYoungestCommonAncestor(
      AncestralTree topAncestor, AncestralTree descendantOne, AncestralTree descendantTwo) {
    // Write your code here.
		int h1=getHeight(descendantOne, topAncestor), h2=getHeight(descendantTwo, topAncestor);

		while(h1 > h2) {
			h1--;
			descendantOne = descendantOne.ancestor;
		}

		while(h2 > h1) {
			h2--;
			descendantTwo = descendantTwo.ancestor;
		}

		while(descendantOne != descendantTwo) {
			descendantOne = descendantOne.ancestor;
			descendantTwo = descendantTwo.ancestor;
		}

    return descendantOne;
  }

	private static int getHeight(AncestralTree node, AncestralTree root) {
		int height = 0;
		while(node != root) {
			height++;
			node = node.ancestor;
		}
		return height;
	}

  static class AncestralTree {
    public char name;
    public AncestralTree ancestor;

    AncestralTree(char name) {
      this.name = name;
      this.ancestor = null;
    }

    // This method is for testing only.
    void addAsAncestor(AncestralTree[] descendants) {
      for (AncestralTree descendant : descendants) {
        descendant.ancestor = this;
      }
    }
  }
}
 */