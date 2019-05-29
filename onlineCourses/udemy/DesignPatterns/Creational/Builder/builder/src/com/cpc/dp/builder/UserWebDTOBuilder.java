package com.cpc.dp.builder;

import java.time.LocalDate;
import java.time.Period;

//The concrete builder for UserWebDTO
public class UserWebDTOBuilder implements UserDTOBuilder {

  private String firstName;
  private String lastName;
  private String age;
  private String address;
  private UserWebDTO dto;

  @Override
  public UserDTOBuilder withFirstName(String fname) {
    firstName = fname;
    return this;
    // "this" is the builder instance
  }

  @Override
  public UserDTOBuilder withLastName(String lname) {
    lastName = lname;
    return this;
  }

  @Override
  public UserDTOBuilder withBirthday(LocalDate date) {
    Period ageInYears = Period.between(date, LocalDate.now());
    age = Integer.toString(ageInYears.getYears());
    return this;
  }

  @Override
  public UserDTOBuilder withAddress(Address address) {
    this.address = address.getHouseNumber()  + " ," + address.getStreet() + "\n" +
      address.getCity() + ", " + address.getState() + " " + address.getZipcode();
    return this;
  }

  //method to "assemble" final product
  @Override
  public UserDTO build() {
    dto = new UserWebDTO(firstName + " " + lastName, address, age);
    return dto;
  }

  //(optional) method to fetch already built object
  @Override
  public UserDTO getUserDTO() {
    return dto;
  }
}
