package com.park.models.parking.spots;

import com.park.models.parking.Floor;
import com.park.models.electronics.DisplayBoard;
import com.park.models.electronics.EntrancePanel;

public class GroundFloor extends Floor {

  private EntrancePanel entrancePanel;

  public EntrancePanel getEntrancePanel() {
    return entrancePanel;
  }

  public void setEntrancePanel(EntrancePanel entrancePanel) {
    this.entrancePanel = entrancePanel;
  }
}
