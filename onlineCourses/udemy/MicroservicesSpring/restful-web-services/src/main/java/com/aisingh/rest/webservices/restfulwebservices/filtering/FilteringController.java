package com.aisingh.rest.webservices.restfulwebservices.filtering;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.Arrays;
import java.util.List;

@RestController
public class FilteringController {

  @GetMapping("/filtering")
  public SomeBean retrieveSomeBean() {
    return new SomeBean("value1", "value2", "value3");
  }

  @GetMapping("/filtering-list")
  public List<SomeBean> retrieveListOfSomeBeans() {
    return Arrays.asList(
      new SomeBean("val 1", "val 2", "val 3"),
      new SomeBean("v1", "v2", "v3")
    );
  }
}
