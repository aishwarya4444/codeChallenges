package com.aisingh.rest.webservices.restfulwebservices.filtering;

import com.fasterxml.jackson.databind.ser.FilterProvider;
import com.fasterxml.jackson.databind.ser.impl.SimpleBeanPropertyFilter;
import com.fasterxml.jackson.databind.ser.impl.SimpleFilterProvider;
import org.springframework.http.converter.json.MappingJacksonValue;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.Arrays;
import java.util.List;

@RestController
public class FilteringController {

  @GetMapping("/filtering")
  public MappingJacksonValue retrieveSomeBean() {
    SomeBean sb = new SomeBean("value1", "value2", "value3");
    SimpleBeanPropertyFilter filter = SimpleBeanPropertyFilter.filterOutAllExcept("field1", "field2");
    FilterProvider filters = new SimpleFilterProvider().addFilter("SomeBeanFilter", filter);
    MappingJacksonValue mapping = new MappingJacksonValue(sb);

    mapping.setFilters(filters);
    return mapping;
  }

  @GetMapping("/filtering-list")
  public MappingJacksonValue retrieveListOfSomeBeans() {
    List<SomeBean> someBeanList = Arrays.asList(
      new SomeBean("val 1", "val 2", "val 3"),
      new SomeBean("v1", "v2", "v3"));
    SimpleBeanPropertyFilter filter = SimpleBeanPropertyFilter.filterOutAllExcept("field3");
    FilterProvider filters = new SimpleFilterProvider().addFilter("SomeBeanFilter", filter);
    MappingJacksonValue mapping = new MappingJacksonValue(someBeanList);

    mapping.setFilters(filters);
    return mapping;
  }
}
