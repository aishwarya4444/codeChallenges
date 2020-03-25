package com.park.models.people;

import com.park.models.Address;
import com.park.models.DBObject;
import com.park.models.accounts.Account;

public class Person extends DBObject {
  private String name;
  private Address address;
  private String phone;
  private final Account account;

  public Person(String name, Account account) {
    this.name = name;
    this.account = account;
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

  public String getPhone() {
    return phone;
  }

  public void setPhone(String phone) {
    this.phone = phone;
  }

  public Account getAccount() {
    return account;
  }
}
