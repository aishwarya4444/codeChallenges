import java.util.*;

class Program {

  public ArrayList<ArrayList<Integer>> solveSudoku(ArrayList<ArrayList<Integer>> board) {
    // Write your code here.
    solvePartialSudoku(0, 0, board);
    return board;
  }

  public boolean solvePartialSudoku(int row, int col, ArrayList<ArrayList<Integer>> board) {
    if(col == board.get(row).size()) {
      row += 1;
      col = 0;
      if(row == board.size()) {
        return true; // board is complete
      }
    }

    if(board.get(row).get(col) == 0) {
      return tryDigitsAtPosition(row, col, board);
    }

    return solvePartialSudoku(row, col+1, board);
  }

  public boolean tryDigitsAtPosition(int row, int col, ArrayList<ArrayList<Integer>> board) {
    for(int digit=1; digit<10; digit++) {
      if(isValidAtPosition(digit, row, col, board)) {
        board.get(row).set(col, digit);
        if(solvePartialSudoku(row, col+1, board)) {
          return true;
        }
      }
    }

    board.get(row).set(col, 0);
    return false;
  }

  public boolean isValidAtPosition(int value, int row, int col, ArrayList<ArrayList<Integer>> board) {
    boolean isRowValid = !board.get(row).contains(value);
    boolean isColValid = true;

    for(int r=0; r<board.size(); r++) {
      if(board.get(r).get(col) == value) {
        isColValid = false;
      }
    }

    if(!isRowValid || !isColValid) {
      return false;
    }

    int subgridRowStart = (row/3)*3;
    int subgridColStart = (col/3)*3;

    for(int r=0; r<3; r++) {
      for(int c=0; c<3; c++) {
        if(value == board.get(r+subgridRowStart).get(c+subgridColStart)) {
          return false;
        }
      }
    }

    return true;
  }
}
