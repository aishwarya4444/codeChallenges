import java.util.*;

class Program {

  public boolean classPhotos(
      ArrayList<Integer> redShirtHeights, ArrayList<Integer> blueShirtHeights) {
    // Write your code here.
    int n, N=redShirtHeights.size(), M=blueShirtHeights.size(), red, blue;
    boolean redSmall = redShirtHeights.get(0) < blueShirtHeights.get(0);

    if(N!=M) {
      return false;
    }

    Collections.sort(redShirtHeights);
    Collections.sort(blueShirtHeights);

    for(n=0; n<N; n++) {
      red = redShirtHeights.get(n);
      blue = blueShirtHeights.get(n);
      if(redSmall) {
        if(red>=blue) {
          return false;
        }
      } else {
        if(blue>=red) {
          return false;
        }
      }
    }
    return true;
  }
}
