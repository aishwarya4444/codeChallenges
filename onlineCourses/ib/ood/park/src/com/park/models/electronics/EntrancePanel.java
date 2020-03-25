package com.park.models.electronics;

import com.park.models.parking.Ticket;
import com.park.models.parking.interfaces.HasDisplay;
import com.park.models.parking.interfaces.IssuesTicket;

public class EntrancePanel extends Electronics implements HasDisplay, IssuesTicket {
  @Override
  public void showMessage(String message) {

  }

  @Override
  public Ticket giveTicket() {
    return null;
  }
}
