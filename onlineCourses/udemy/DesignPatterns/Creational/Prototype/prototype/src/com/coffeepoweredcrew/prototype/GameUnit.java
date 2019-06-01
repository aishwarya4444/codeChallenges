package com.coffeepoweredcrew.prototype;

import javafx.geometry.Point3D;

/**
 * This class represents an abstract prototype & defines the clone method
 */
public abstract class GameUnit implements Cloneable{
	
	private Point3D position;
	// Point3D is immutable class
	
	public GameUnit() {
		position = Point3D.ZERO;
	}
	
	@Override
	public GameUnit clone() throws CloneNotSupportedException {
		// 'GameUnit' is written instead of 'Object'
		// this is covariant
		// clone method makes a shallow copy
		GameUnit unit = (GameUnit )super.clone();
		unit.initialize();
		return unit;
	}
	
	public void initialize() {
		this.position = Point3D.ZERO;
		reset();
	}
	
	public abstract void reset();
	
	public GameUnit(float x, float y, float z) {
		position = new Point3D(x, y, z);
	}

	public void move(Point3D direction, float distance) {
		Point3D finalMove = direction.normalize();
		finalMove = finalMove.multiply(distance);
		position = position.add(finalMove);
	}
	
	public Point3D getPosition() {
		return position;
	}
}
