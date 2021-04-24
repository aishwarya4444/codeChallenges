import java.util.*;

class Program {
  public static OrgChart getLowestCommonManager(
      OrgChart topManager, OrgChart reportOne, OrgChart reportTwo) {
    // Write your code here.
    return getLCM(topManager, reportOne, reportTwo).manager;
  }

  static class ManagerInfo {
    public OrgChart manager;
    public int matchedReports;
    ManagerInfo(OrgChart manager, int matchedReports) {
      this.manager = manager;
      this.matchedReports = matchedReports;
    }
  }

  private static ManagerInfo getLCM(OrgChart root, OrgChart r1, OrgChart r2) {

    int matchedReports = 0;
    for(OrgChart report: root.directReports) {
      ManagerInfo managerInfo = getLCM(report, r1, r2);
      if(managerInfo.manager != null) {
        return managerInfo;
      }
      matchedReports += managerInfo.matchedReports;
    }

    if(root==r1 || root==r2) {
      matchedReports++;
    }

    if(matchedReports == 2) {
      return new ManagerInfo(root, matchedReports);
    } else {
      return new ManagerInfo(null, matchedReports);
    }
  }

  static class OrgChart {
    public char name;
    public List<OrgChart> directReports;

    OrgChart(char name) {
      this.name = name;
      this.directReports = new ArrayList<OrgChart>();
    }

    // This method is for testing only.
    public void addDirectReports(OrgChart[] directReports) {
      for (OrgChart directReport : directReports) {
        this.directReports.add(directReport);
      }
    }
  }
}
