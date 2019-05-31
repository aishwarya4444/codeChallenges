package com.coffeepoweredcrew.singleton;

/**
 * Singleton pattern using lazy initialization holder class. This ensures that, we have a lazy initialization
 * without worrying about synchronization.
 */
public class LazyRegistryIODH {
	
	private LazyRegistryIODH() {
		// IODH - Initialization-on-demand holder idiom
		System.out.println("IODH");
	}
	
	private static class RegistryHolder {
		static LazyRegistryIODH INSTANCE = new LazyRegistryIODH();
	}
	
	public static LazyRegistryIODH getInstance() {
		return RegistryHolder.INSTANCE;
	}

}
