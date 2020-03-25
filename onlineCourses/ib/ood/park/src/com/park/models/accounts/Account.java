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

  public String getUserName() {
    return userName;
  }

  public void setUserName(String userName) {
    this.userName = userName;
  }

  public String getSaltedPasswordHash() {
    return saltedPasswordHash;
  }

  public void setSaltedPasswordHash(String saltedPasswordHash) {
    this.saltedPasswordHash = saltedPasswordHash;
  }

  public Person getPerson() {
    return person;
  }

  public AccountStatus getAccountStatus() {
    return accountStatus;
  }

  public void setAccountStatus(AccountStatus accountStatus) {
    this.accountStatus = accountStatus;
  }
}
