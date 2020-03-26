package com.park.models.parking.spots;

import com.park.exceptions.MalformedVehicleException;
import com.park.exceptions.SpotAlreadyFreeException;
import com.park.exceptions.SpotAlreadyOccupiedException;
import com.park.models.DBObject;
import com.park.models.vehicles.Vehicle;

public abstract class Spot extends DBObject {
  private final SpotType type;
  private SpotStatus status;
  private Vehicle vehicle;

  public Spot(SpotType type) {
    this.type = type;
  }

  public SpotType getType() {
    return type;
  }

  public SpotStatus getStatus() {
    return status;
  }

  public void setStatus(SpotStatus status) {
    this.status = status;
  }

  public void park(Vehicle vehicle) throws SpotAlreadyOccupiedException, MalformedVehicleException {
    if(!status.equals(SpotStatus.FREE)) {
      throw new SpotAlreadyOccupiedException(this.toString() + "is already occupied!");
    }
    if(!vehicle.getType().getFitsIn().contains(this.getType())) {
      throw new MalformedVehicleException(vehicle.getType().toString() + "does not fit in" + this.toString());
    }
    this.vehicle = vehicle;
    this.status = SpotStatus.OCCUPIED;
  }

  public Vehicle unpark() throws SpotAlreadyFreeException {
    if(!status.equals(SpotStatus.OCCUPIED)) {
      throw new SpotAlreadyFreeException(this.toString() + " is already free!");
    }
    Vehicle vehicle = this.vehicle;
    vehicle = null;
    status = SpotStatus.FREE;
    return vehicle;
  }

  @Override
  public String toString() {
    return "Spot{" +
      "type=" + type +
      ", status=" + status +
      ", vehicle=" + vehicle +
      '}';
  }
}
