package com.park.models.accounts;

import com.park.models.DBObject;
import com.park.models.people.Person;

public abstract class Account extends DBObject {
  private String userName;
  private String saltedPasswordHash;
  private final Person person;
  private AccountStatus accountStatus;

  public Account(String userName, String saltedPasswordHash, Person person) {
    this.userName = userName;
    this.saltedPasswordHash = saltedPasswordHash;
    this.person = person;
    this.accountStatus = AccountStatus.ACTIVE;
  }
}
