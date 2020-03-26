package com.park.models.parking;

import com.park.exceptions.MalformedVehicleException;
import com.park.exceptions.SpotAlreadyFreeException;
import com.park.exceptions.SpotAlreadyOccupiedException;
import com.park.exceptions.SpotNotAddedException;
import com.park.models.electronics.CustomerInfoPortal;
import com.park.models.electronics.DisplayBoard;
import com.park.models.parking.spots.Spot;
import com.park.models.parking.spots.SpotStatus;
import com.park.models.parking.spots.SpotType;
import com.park.models.vehicles.Vehicle;

import java.util.*;

public class Floor {
  private CustomerInfoPortal customerInfoPortal;
  private Map<SpotType, Set<Spot>> freeSpots;
  private Map<SpotType, Set<Spot>> occupiedSpots;
  private DisplayBoard displayBoard;
  private String name;

  public Floor() {
  }

  public Floor(String name) {
    this.name = name;
    displayBoard = new DisplayBoard();
    freeSpots = new HashMap<>();
    occupiedSpots = new HashMap<>();
    customerInfoPortal = new CustomerInfoPortal();
  }

  private void populateMap(SpotType type) {
    if(!freeSpots.containsKey(type)) {
      freeSpots.put(type, new HashSet<>());
    }
    if(!occupiedSpots.containsKey(type)) {
      occupiedSpots.put(type, new HashSet<>());
    }
  }

  public void addSpot(Spot spot) throws SpotAlreadyOccupiedException {
    populateMap(spot.getType());
    if(!spot.getStatus().equals(SpotStatus.FREE) || occupiedSpots.get(spot.getType()).contains(spot)) {
      throw new SpotAlreadyOccupiedException("Cant move " + spot.toString() + " because it is occupied!");
    }
    freeSpots.get(spot.getType()).add(spot);
  }

  public synchronized void park(Spot spot, Vehicle vehicle) throws SpotAlreadyOccupiedException, MalformedVehicleException, SpotNotAddedException {
    populateMap(spot.getType());
    if(!freeSpots.get(spot.getType()).contains(spot)) {
      throw new SpotNotAddedException("Spot must be added to floor before it can be parked in");
    }
    spot.park(vehicle);
    freeSpots.get(spot.getType()).remove(spot);
    occupiedSpots.get(spot.getType()).add(spot);
    updateDisplayBoard();
  }

  public synchronized Vehicle unpark(Spot spot) throws SpotNotAddedException, SpotAlreadyFreeException {
    populateMap(spot.getType());
    if(!occupiedSpots.get(spot.getType()).contains(spot)) {
      throw new SpotNotAddedException("Spot must be added to floor before it can be unparked");
    }
    Vehicle vehicle = spot.unpark();
    occupiedSpots.get(spot.getType()).remove(spot);
    freeSpots.get(spot.getType()).add(spot);
    updateDisplayBoard();
    return vehicle;
  }

  public void updateDisplayBoard() {
    StringBuilder message = new StringBuilder();
    message.append(this.toString()).append("\n");
//    String message = "";
    for(SpotType type: freeSpots.keySet()) {
      Set<Spot> spots = freeSpots.get(type);
      message.append("\n").append(type.toString()).append(" : ");
//      message += "\n" + type.toString();
      if(spots.size() == 0) {
        message.append("No free spots");
//        message += "No free spots";
      } else {
        message.append(spots.iterator().next().toString());
//        message += spots.iterator().next().toString();
      }
    }
    displayBoard.showMessage(message.toString());
//    displayBoard.showMessage(message);
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }
}
