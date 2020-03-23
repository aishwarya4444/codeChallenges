package com.park.vehicles;

public abstract class Vehicle {
  private String vehicleNumber;
  private String color;
  private final VehicleType type;

  public Vehicle(VehicleType type) {
    this.type = type;
  }
}
