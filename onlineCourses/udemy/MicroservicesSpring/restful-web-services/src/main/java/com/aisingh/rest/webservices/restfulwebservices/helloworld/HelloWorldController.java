package com.aisingh.rest.webservices.restfulwebservices.helloworld;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HelloWorldController {

  @GetMapping(path = "/helloWorld")
  public String helloWorld() {
    return "Hello World";
  }

  @GetMapping(path = "/helloWorldBean")
  public HelloWorldBean helloWorldBean() {
    return new HelloWorldBean("Hello World");
  }

  @GetMapping(path = "/helloWorld/path-variable/{user}")
  public HelloWorldBean helloWorldBean(@PathVariable String user) {
    return new HelloWorldBean(String.format("Hello World, %s", user));
  }
}
