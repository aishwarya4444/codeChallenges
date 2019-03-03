package com.aisingh.rest.webservices.restfulwebservices;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HelloWorldController {
  @RequestMapping(method = RequestMethod.GET, path = "/helloWorld")
  public String helloWorld() {
    return "Hello World";
  }
}
