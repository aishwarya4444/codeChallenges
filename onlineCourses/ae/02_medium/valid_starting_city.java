import java.util.*;

class Program {

  public int validStartingCity(int[] distances, int[] fuel, int mpg) {
    // Write your code here.
    // O(n^2)
    int i, city, C=fuel.length, dist;

    for(i=0; i<C; i++) {
      dist = 0;
      for(city=i; city<i+C; city++) {
        if(dist<0) {
          break;
        }
        dist += fuel[city%C]*mpg - distances[city%C];
      }
      if(dist >= 0) {
        return i;
      }
    }
    return -1;
  }
}

/*
import java.util.*;

class Program {

  public int validStartingCity(int[] distances, int[] fuel, int mpg) {
    // Write your code here.
		int idx=0, city, C=fuel.length, dist=0, potential=0;

		for(city=0; city<C; city++) {
			potential += fuel[city]*mpg - distances[city];
			if(potential < 0) {
				dist += potential;
				potential = 0;
				idx = city+1;
			}
		}
    return dist+potential>=0 ? idx : -1;
  }
}
 */