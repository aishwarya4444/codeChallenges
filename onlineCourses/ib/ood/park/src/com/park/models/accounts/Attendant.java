package com.park.models.accounts;

import com.park.models.parking.Ticket;
import com.park.models.parking.interfaces.IssuesTicket;
import com.park.models.parking.interfaces.PaymentEnabled;
import com.park.models.Person;

public class Attendant extends Account implements IssuesTicket, PaymentEnabled {
  public Attendant(String userName, String saltedPasswordHash, Person person) {
    super(userName, saltedPasswordHash, person);
  }

  @Override
  public Ticket giveTicket() {
    return null;
  }

  @Override
  public void processTicket(Ticket ticket) {

  }

  @Override
  public void processPayment() {

  }
}
