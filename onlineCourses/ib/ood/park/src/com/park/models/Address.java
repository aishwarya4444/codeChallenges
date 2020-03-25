package com.park.models;

public class Address {
  private String country;
  private String state;
  private String city;
  private String zipCode;
  private String streetAdress;

  public Address(String country, String state, String city, String zipCode, String streetAdress) {
    this.country = country;
    this.state = state;
    this.city = city;
    this.zipCode = zipCode;
    this.streetAdress = streetAdress;
  }

  public static final class Builder {
    private String country;
    private String state;
    private String city;
    private String zipCode;
    private String streetAdress;

    public Builder() {

    }

    public Builder setCountry(String country) {
      if(country == null) {
        this.country = "India";
      } else {
        this.country = country;
      }
      return this;
    }

    public Builder setState(String state) {
      this.state = state;
      return this;
    }

    public Builder setCity(String city) {
      this.city = city;
      return this;
    }

    public Builder setZipCode(String zipCode) {
      this.zipCode = zipCode;
      return this;
    }

    public Builder setStreetAdress(String streetAdress) {
      this.streetAdress = streetAdress;
      return this;
    }

    public Address build() {
      return new Address(country, state, city, zipCode, streetAdress);
    }
  }

}
