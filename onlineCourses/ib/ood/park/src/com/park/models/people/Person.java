package com.park.models.people;

import com.park.models.DBObject;
import com.park.models.accounts.Account;

public class Person extends DBObject {
  private String name;
  private String address;
  private String phone;
  private final Account account;

  public Person(String name, Account account) {
    this.name = name;
    this.account = account;
  }
}
