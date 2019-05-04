package com.aisingh.rest.webservices.restfulwebservices.user;

import javax.validation.constraints.Past;
import javax.validation.constraints.Size;
import java.util.Date;

public class User {

  private Integer id;

  @Size(min = 2, message = "Name should have atleast 2 characters")
  private String name;

  @Past
  private Date birthDate;

  protected User() {
    // error occurs during POST if no arg constructor is missing
  }

  public User(Integer id, String name, Date birthDate) {
    this.id = id;
    this.name = name;
    this.birthDate = birthDate;
  }

  public Integer getId() {
    return id;
  }

  public String getName() {
    return name;
  }

  public Date getBirthDate() {
    return birthDate;
  }

  public void setId(Integer id) {
    this.id = id;
  }

  public void setName(String name) {
    this.name = name;
  }

  public void setBirthDate(Date birthDate) {
    this.birthDate = birthDate;
  }
}