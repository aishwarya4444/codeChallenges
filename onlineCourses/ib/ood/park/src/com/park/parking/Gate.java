package com.park.parking;

public abstract class Gate {
  private long uid;
  private String gateNumber;

  abstract void open();
  abstract void close();
}
