package com.park.models.vehicles;

import com.park.models.DBObject;

public abstract class Vehicle extends DBObject {
  private String vehicleNumber;
  private String color;
  private final VehicleType type;

  public Vehicle(VehicleType type) {
    this.type = type;
  }
}
