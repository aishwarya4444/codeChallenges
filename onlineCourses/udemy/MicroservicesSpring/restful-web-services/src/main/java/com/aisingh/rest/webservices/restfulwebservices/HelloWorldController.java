package com.aisingh.rest.webservices.restfulwebservices;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HelloWorldController {

  @GetMapping(path = "/helloWorld")
  public String helloWorld() {
    return "Hello World";
  }
}
