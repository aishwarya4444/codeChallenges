package com.park;

import com.park.models.Address;

public class Main {

    public static void main(String[] args) {
        System.out.println("hello");
        Address a = new Address.Builder().
          setCountry("India").
          setState("UP").
          setCity("Kanpur").
          setZipCode("211002").
          setStreetAdress("3A Minto Road").
          build();
    }
}
