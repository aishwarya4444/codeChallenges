package com.coffeepoweredcrew.objectpool;

import javafx.geometry.Point2D;
//Represents our abstract reusable
public interface Image{

    void draw();

    Point2D getLocation();

    void setLocation(Point2D location);
}
