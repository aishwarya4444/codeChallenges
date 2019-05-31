package com.coffeepoweredcrew.singleton;

/**
 * (Ref. Google I/O 2k8 Joshua Bloch)
 * Since Java 1.5 using enum we can create a singleton. It handles serialization using java's in-built
 * mechanism and still ensure single instance
 */
public enum RegistryEnum {

	INSTANCE;

	private int count;

	public void setCount(int count) {
		this.count = count;
	}

	public void doProcess() {
		System.out.println("Do high memory or CPU consume operation. count : " + this.count);
	}

}