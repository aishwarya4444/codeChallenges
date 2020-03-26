package com.park.models;

import com.park.models.accounts.Account;

public class Person extends DBObject {
  private String name;
  private Address address;
  private String phoneNumber;
  private final Account account;

  public Person(Builder builder) {
    setName(builder.name);
    setAddress(builder.address);
    setPhoneNumber(builder.phoneNumber);
    this.account = builder.account;
  }

  @Override
  public String toString() {
    return "Person{" +
      "name='" + name + '\'' +
      ", address=" + address +
      ", phoneNumber='" + phoneNumber + '\'' +
      ", account=" + account +
      '}';
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public Address getAddress() {
    return address;
  }

  public void setAddress(Address address) {
    this.address = address;
  }

  public String getPhoneNumber() {
    return phoneNumber;
  }

  public void setPhoneNumber(String phoneNumber) {
    this.phoneNumber = phoneNumber;
  }

  public Account getAccount() {
    return account;
  }

  public static final class Builder {
    private String name;
    private Address address;
    private String phoneNumber;
    private Account account;

    public Builder(String name) {
      this.name = name;
    }

    public Builder setName(String name) {
      this.name = name;
      return this;
    }

    public Builder setAddress(Address address) {
      this.address = address;
      return this;
    }

    public Builder setPhoneNumber(String phoneNumber) {
      this.phoneNumber = phoneNumber;
      return this;
    }

    public Builder setAccount(Account account) {
      this.account = account;
      return this;
    }

    public Person build() {
      return new Person(this);
    }
  }
}
