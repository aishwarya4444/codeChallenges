package com.park.models.accounts;

import com.park.models.people.Person;

public class Attendant extends Account {
  public Attendant(String userName, String saltedPasswordHash, Person person) {
    super(userName, saltedPasswordHash, person);
  }
}
