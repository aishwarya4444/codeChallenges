package com.company.openclose;

import java.util.List;

public class PhoneSubscriber extends Subscriber {

  private int baseRate;

  // for demo purpose : open for extension
  @Override
  public double calculateBill() {
    List<CallHistory.Call> sessions = CallHistory.getCurrentCalls(subscriberId);
    long totalDuration = sessions.stream().mapToLong(CallHistory.Call::getDuration).sum();
    return totalDuration*baseRate/100;
  }

  /**
   * @param phoneNumber the phoneNumber to set
   */
  public void setPhoneNumber(Long phoneNumber) {
    this.phoneNumber = phoneNumber;
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

}