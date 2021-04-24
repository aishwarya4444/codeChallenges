import java.util.*;

class Program {

  public String tournamentWinner(
      ArrayList<ArrayList<String>> competitions, ArrayList<Integer> results) {
    // Write your code here.
    int n, N=results.size(), maxScore=0;
    String winner="";

    Map<String, Integer> score = new HashMap<>();

    for(n=0; n<N; n++) {
      String home = competitions.get(n).get(0);
      String away = competitions.get(n).get(1);
      if(results.get(n) == 1) {
        score.put(home, score.getOrDefault(home, 0)+3);
        if(score.get(home) > maxScore) {
          maxScore = score.get(home);
          winner = home;
        }
      } else {
        score.put(away, score.getOrDefault(away, 0)+3);
        if(score.get(away) > maxScore) {
          maxScore = score.get(away);
          winner = away;
        }
      }
    }
    return winner;
  }
}
