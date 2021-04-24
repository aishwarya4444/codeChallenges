import java.util.*;

class Program  {

  // Upper Bound: O(n!) time | O(n) space - where n is the input number
  public int nonAttackingQueens(int n) {
    HashSet<Integer> blockedColumns = new HashSet<Integer>();
    HashSet<Integer> blockedUpDiagonals = new HashSet<Integer>();
    HashSet<Integer> blockedDownDiagonals = new HashSet<Integer>();
    return getNumberOfNonAttackingQueenPlacements( 0, blockedColumns, blockedUpDiagonals, blockedDownDiagonals, n);
  }

  public int getNumberOfNonAttackingQueenPlacements( int row, HashSet<Integer> blockedColumns, HashSet<Integer> blockedUpDiagonals, HashSet<Integer> blockedDownDiagonals, int boardSize) {
    if (row == boardSize) return 1;

    int validPlacements = 0;
    for (int col = 0; col < boardSize; col++) {
      if (isNonAttackingPlacement( row, col, blockedColumns, blockedUpDiagonals, blockedDownDiagonals)) {
        placeQueen(row, col, blockedColumns, blockedUpDiagonals, blockedDownDiagonals);
        validPlacements += getNumberOfNonAttackingQueenPlacements( row + 1, blockedColumns, blockedUpDiagonals, blockedDownDiagonals, boardSize);
        removeQueen(row, col, blockedColumns, blockedUpDiagonals, blockedDownDiagonals);
      }
    }

    return validPlacements;
  }

  // This is always an O(1)-time operation.
  public boolean isNonAttackingPlacement(int row, int col, HashSet<Integer> blockedColumns, HashSet<Integer> blockedUpDiagonals, HashSet<Integer> blockedDownDiagonals) {
    if (blockedColumns.contains(col)) {
      return false;
    } else if (blockedUpDiagonals.contains(row + col)) {
      return false;
    } else if (blockedDownDiagonals.contains(row - col)) {
      return false;
    }

    return true;
  }

  public void placeQueen(int row, int col, HashSet<Integer> blockedColumns, HashSet<Integer> blockedUpDiagonals, HashSet<Integer> blockedDownDiagonals) {
    blockedColumns.add(col);
    blockedUpDiagonals.add(row + col);
    blockedDownDiagonals.add(row - col);
  }

  public void removeQueen(int row, int col, HashSet<Integer> blockedColumns, HashSet<Integer> blockedUpDiagonals, HashSet<Integer> blockedDownDiagonals) {
    blockedColumns.remove(col);
    blockedUpDiagonals.remove(row + col);
    blockedDownDiagonals.remove(row - col);
  }
}
