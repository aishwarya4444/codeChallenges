package com.park.models.parking;

import com.park.models.DBObject;
import com.park.models.accounts.Attendant;
import com.park.models.electronics.AutoExitPanel;
import com.park.models.parking.interfaces.PaymentEnabled;

public abstract class Gate extends DBObject implements PaymentEnabled {
  private GateType type;
  private String gateName;
  private Attendant attendant;
  private AutoExitPanel exitPanel;

  void open() {

  }

  void close() {

  }

  void getTicket() {

  }

  @Override
  public void processTicket(Ticket ticket) {

  }

  public GateType getType() {
    return type;
  }

  public void setType(GateType type) {
    this.type = type;
  }

  public String getGateName() {
    return gateName;
  }

  public void setGateName(String gateName) {
    this.gateName = gateName;
  }

  public Attendant getAttendant() {
    return attendant;
  }

  public void setAttendant(Attendant attendant) {
    this.attendant = attendant;
  }

  public AutoExitPanel getExitPanel() {
    return exitPanel;
  }

  public void setExitPanel(AutoExitPanel exitPanel) {
    this.exitPanel = exitPanel;
  }
}
