import java.util.*;

class Program {
  // O(n^2) time | O(n) space - where n is the number of points
  public int minimumAreaRectangle(int[][] points) {
    HashSet<String> pointSet = createPointSet(points);
    int minimumAreaFound = Integer.MAX_VALUE;

    for (int currentIdx = 0; currentIdx < points.length; currentIdx++) {
      int p2x = points[currentIdx][0];
      int p2y = points[currentIdx][1];

      for (int previousIdx = 0; previousIdx < currentIdx; previousIdx++) {
        int p1x = points[previousIdx][0];
        int p1y = points[previousIdx][1];
        boolean pointsShareValue = p1x == p2x || p1y == p2y;

        if (pointsShareValue) continue;

        // If (p1x, p2y) and (p2x, p1y), exist we've found a rectangle.
        boolean point1OnOppositeDiagonalExists = pointSet.contains(convertPointToString(p1x, p2y));
        boolean point2OnOppositeDiagonalExists = pointSet.contains(convertPointToString(p2x, p1y));
        boolean oppositeDiagonalExists = point1OnOppositeDiagonalExists && point2OnOppositeDiagonalExists;

        if (oppositeDiagonalExists) {
          int currentArea = Math.abs(p2x - p1x) * Math.abs(p2y - p1y);
          minimumAreaFound = Math.min(minimumAreaFound, currentArea);
        }
      }
    }

    return (minimumAreaFound != Integer.MAX_VALUE) ? minimumAreaFound : 0;
  }

  public String convertPointToString(int x, int y) {
    return String.valueOf(x) + ":" + String.valueOf(y);
  }

  public HashSet<String> createPointSet(int[][] points) {
    HashSet<String> pointSet = new HashSet<String>();
    for (int[] point : points) {
      int x = point[0];
      int y = point[1];
      String pointString = convertPointToString(x, y);
      pointSet.add(pointString);
    }
    return pointSet;
  }
}
