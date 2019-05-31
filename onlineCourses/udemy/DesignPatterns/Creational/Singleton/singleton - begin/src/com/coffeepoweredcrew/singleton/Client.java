package com.coffeepoweredcrew.singleton;

public class Client {

	public static void main(String[] args) {

		// eager singleton
		EagerRegistry registry = EagerRegistry.getInstance();
		EagerRegistry registry2 = EagerRegistry.getInstance();
		System.out.println(registry == registry2);

		// lazy singleton
		LazyRegistryWithDCL lazySingleton1 = LazyRegistryWithDCL.getInstance();
		LazyRegistryWithDCL lazySingleton2 = LazyRegistryWithDCL.getInstance();
		System.out.println(lazySingleton1 == lazySingleton2);
		
		// IODH - Initialization-on-demand holder idiom
		LazyRegistryIODH iodh;
		iodh = LazyRegistryIODH.getInstance();
		iodh = LazyRegistryIODH.getInstance();
		iodh = LazyRegistryIODH.getInstance();
		iodh = LazyRegistryIODH.getInstance();
	}

}
