package com.park;

import com.park.models.Address;
import com.park.models.Person;

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

        Person atul = new Person.Builder("Atul")
          .setAddress(a)
          .setPhoneNumber("9820420420")
          .build();

        System.out.println(a.toString());
        System.out.println(atul);
    }
}
