package com.park.models.parking;

import com.park.models.electronics.CustomerInfoPortal;
import com.park.models.electronics.DisplayBoard;
import com.park.models.parking.spots.Spot;

import java.util.List;

public class Floor {
  private CustomerInfoPortal customerInfoPortal;
  private List<Spot> spots;
  private DisplayBoard displayBoard;
}
