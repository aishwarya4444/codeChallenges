package com.park.models.parking.spots;

import com.park.models.parking.SpotType;
import com.park.models.electronics.ChargingPanel;

public class ElectricSpot extends Spot {
  private ChargingPanel chargingPanel;
  public ElectricSpot(SpotType type) {
    super(SpotType.ELECTRIC);
  }
}
