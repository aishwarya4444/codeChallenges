package com.park.models.parking.spots;

import com.park.models.parking.SpotType;

public abstract class Spot {
  private final SpotType type;
  private SpotStatus status;

  public Spot(SpotType type) {
    this.type = type;
  }
}
