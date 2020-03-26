package com.park.models.electronics;

import com.park.models.parking.Ticket;
import com.park.models.parking.interfaces.PaymentEnabled;

public class CustomerInfoPortal extends Electronics implements PaymentEnabled {
  @Override
  public void processTicket(Ticket ticket) {

  }

  @Override
  public void processPayment() {

  }
}
