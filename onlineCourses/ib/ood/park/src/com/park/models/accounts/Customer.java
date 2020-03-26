package com.park.models.accounts;

import com.park.models.parking.Ticket;
import com.park.models.Person;

public class Customer extends Account {
  public Customer(String name, String saltedPasswordHash, Person person) {
    super(name, saltedPasswordHash, person);
  }

  public Ticket getTicket() {
    return null;
  }

  public void payForTicket(Ticket ticket) {

  }
}
