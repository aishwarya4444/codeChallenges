package com.park.models.parking;

import com.park.models.AutoExitPanel;
import com.park.models.DBObject;
import com.park.models.Attendant;

public abstract class Gate extends DBObject {
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
}
