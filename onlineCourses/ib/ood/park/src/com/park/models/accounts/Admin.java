package com.park.models.accounts;

import com.park.models.electronics.Electronics;
import com.park.models.parking.Floor;
import com.park.models.parking.Gate;
import com.park.models.parking.spots.Spot;
import com.park.models.Person;

public class Admin extends Account {
  public Admin(String userName, String saltedPasswordHash, Person person) {
    super(userName, saltedPasswordHash, person);
  }

  void addFloor(Floor floor) {

  }

  void removeFloor(Floor floor) {

  }

  void modifyFloor(Floor floor) {

  }

  void addSpot(Floor floor, Spot spot) {

  }

  void modifySpot(Floor floor, Spot spot) {

  }

  void removeSpot(Floor floor, Spot spot) {

  }

  void addElectronics(Floor floor, Electronics panel) {

  }

  void modifyElectronics(Floor floor, Electronics spot) {

  }

  void removeElectronics(Floor floor, Electronics spot) {

  }

  void addAttendant(Floor floor, Attendant attendant) {

  }

  void modifyAttendant(Floor floor, Attendant attendant) {

  }

  void removeAttendant(Floor floor, Attendant attendant) {

  }

  void addGate(Gate gate) {

  }

  void modifyGate(Gate gate) {

  }

  void removeGate(Gate gate) {

  }
}
