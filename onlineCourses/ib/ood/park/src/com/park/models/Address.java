package com.park.models;

public class Address {
  private String country;
  private String state;
  private String city;
  private String zipCode;
  private String streetAdress;

  public Address(Builder builder) {
    country = builder.country;
    state = builder.state;
    city = builder.city;
    zipCode = builder.zipCode;
    streetAdress = builder.streetAdress;
  }

  @Override
  public String toString() {
    return "Address{" +
      "country='" + country + '\'' +
      ", state='" + state + '\'' +
      ", city='" + city + '\'' +
      ", zipCode='" + zipCode + '\'' +
      ", streetAdress='" + streetAdress + '\'' +
      '}';
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
      return new Address(this);
    }
  }

}
