package com.park.models.accounts;

import com.park.models.people.Person;

public class Customer extends Person {
  public Customer(String name, Account account) {
    super(name, account);
  }
}
