package com.company.openclose;

import java.util.List;

public class ISPSubscriber extends Subscriber {

  private int baseRate;

  private long freeUsage;

  public ISPSubscriber() {

  }

  // for demo purpose : open for extension
  @Override
  public double calculateBill() {
    List<InternetSessionHistory.InternetSession> sessions = InternetSessionHistory.getCurrentSessions(subscriberId);
    long totalData = sessions.stream().mapToLong(InternetSessionHistory.InternetSession::getDataUsed).sum();
    long chargeableData = totalData - freeUsage;
    return chargeableData*baseRate/100;
  }

  /**
   * @return the baseRate
   */
  public int getBaseRate() {
    return baseRate;
  }

  /**
   * @param baseRate the baseRate to set
   */
  public void setBaseRate(int baseRate) {
    this.baseRate = baseRate;
  }

  /**
   * @return the freeUsage
   */
  public long getFreeUsage() {
    return freeUsage;
  }

  /**
   * @param freeUsage the freeUsage to set
   */
  public void setFreeUsage(long freeUsage) {
    this.freeUsage = freeUsage;
  }


}