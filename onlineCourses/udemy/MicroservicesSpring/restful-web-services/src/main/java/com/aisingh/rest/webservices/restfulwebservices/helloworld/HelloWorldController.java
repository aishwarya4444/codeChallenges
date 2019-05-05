package com.aisingh.rest.webservices.restfulwebservices.helloworld;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.MessageSource;
import org.springframework.context.i18n.LocaleContextHolder;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestHeader;
import org.springframework.web.bind.annotation.RestController;

import java.util.Locale;

@RestController
public class HelloWorldController {

  @Autowired
  private MessageSource messageSource;

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

  @GetMapping(path = "/helloWorld_i18")
  public String helloWorld_i18() {
    return messageSource.getMessage("good.morning.message", null, LocaleContextHolder.getLocale());
  }
}
