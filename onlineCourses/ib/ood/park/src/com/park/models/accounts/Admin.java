package com.park.models.accounts;

import com.park.models.people.Person;

public class Admin extends Account {
  public Admin(String userName, String saltedPasswordHash, Person person) {
    super(userName, saltedPasswordHash, person);
  }
}
