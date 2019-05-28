package com.company.openclose;

// base class - closed for modification
public abstract class Subscriber {

  protected Long subscriberId;

  private String address;

  protected Long phoneNumber;

  public Long getSubscriberId() {
    return subscriberId;
  }

  public void setSubscriberId(Long subscriberId) {
    this.subscriberId = subscriberId;
  }

  public String getAddress() {
    return address;
  }

  public void setAddress(String address) {
    this.address = address;
  }

  public Long getPhoneNumber() {
    return phoneNumber;
  }

  public void setPhoneNumber(Long phoneNumber) {
    this.phoneNumber = phoneNumber;
  }

  // extension provided by base class
  public abstract double calculateBill();
}
