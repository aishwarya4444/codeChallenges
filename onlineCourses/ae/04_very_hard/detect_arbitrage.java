import java.util.*;

class Program {

  // O(n"3) time I O(n"2) space - where n is the number of currencies
  public boolean detectArbitrage(ArrayList<ArrayList<Double>> exchangeRates) {
    // To use exchange rates as edge weights, we must be able to add them.
    // Since log(a*b) = log(a) + log(b), we can convert all rates to
    // -log10(rate) to use them as edge weights.
    ArrayList<ArrayList<Double>> logExchangeRates = convertToLogMatrix(exchangeRates);

    // A negative weight cycle indicates an arbitrage.
    return foundNegativeWeightCycle(logExchangeRates, 0);
  }

  // Runs the Bellman—Ford Algorithm to detect any negative-weight cycles.
  public boolean foundNegativeWeightCycle(ArrayList<ArrayList<Double>> graph, int start) {
    double[] distancesFromStart = new double[graph.size()];
    Arrays. fill(distancesFromStart, Double.MAX_VALUE);
    distancesFromStart[start] = 0;
    for (int unused = 0; unused < graph.size(); unused++) {
      // If no update occurs, that means there's no negative cycle.
      if (!relaxEdgesAndUpdateDistances(graph, distancesFromStart)) {
        return false;
      }
    }
    return relaxEdgesAndUpdateDistances(graph, distancesFromStart);
  }

  // Returns 'true' if any distance was updated
  public boolean relaxEdgesAndUpdateDistances( ArrayList<ArrayList<Double>> graph, double[] distances) {
    boolean updated = false;
    for (int sourceIdx = 0; sourceIdx < graph.size(); sourceIdx++) {
      ArrayList<Double> edges = graph.get(sourceIdx);
      for (int destinationIdx = 0; destinationIdx < edges.size(); destinationIdx++) {
        double edgeWeight = edges.get(destinationIdx);
        double newDistanceToDestination = distances[sourceIdx] + edgeWeight;
        if (newDistanceToDestination < distances[destinationIdx]) {
          updated = true; distances[destinationIdx] = newDistanceToDestination;
        }
      }
    }
    return updated;
  }

  public ArrayList<ArrayList<Double>> convertToLogMatrix(ArrayList<ArrayList<Double>> matrix) {
    ArrayList<ArrayList<Double>> newMatrix = new ArrayList<ArrayList<Double>>();
    for (int row = 0; row < matrix.size(); row++) {
      ArrayList<Double> rates = matrix.get(row);
      newMatrix.add(new ArrayList<Double>());
      for (Double rate : rates) {
        newMatrix.get(row).add(-Math.log10(rate));
      }
    }

    return newMatrix;
  }

}
