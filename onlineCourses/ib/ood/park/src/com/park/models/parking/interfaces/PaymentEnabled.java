package com.park.models.parking.interfaces;

import com.park.models.parking.Ticket;

public interface PaymentEnabled {
  public void processTicket(Ticket ticket) ;
}
