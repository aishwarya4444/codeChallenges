package com.aisingh.rest.webservices.restfulwebservices.user;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.hateoas.Resource;
import org.springframework.hateoas.mvc.ControllerLinkBuilder;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.support.ServletUriComponentsBuilder;

import static org.springframework.hateoas.mvc.ControllerLinkBuilder.linkTo;
import static org.springframework.hateoas.mvc.ControllerLinkBuilder.methodOn;

import javax.validation.Valid;
import java.net.URI;
import java.util.List;

@RestController
public class UserResource {

  @Autowired
  private UserDaoService service;

  @GetMapping("/users")
  public List<User> retrieveAllUsers() {
    return service.findAll();
  }

  @GetMapping("/users/{id}")
  public Resource<User> retrieveUser(@PathVariable int id) {
    User user = service.findOne(id);
    if(user==null) {
      throw new UserNotFoundException("id-"+id);
    }
    Resource<User> resource = new Resource<User>(user);
    ControllerLinkBuilder linkTo = linkTo(methodOn(this.getClass()).retrieveAllUsers());
    resource.add(linkTo.withRel("all-users"));
    return resource;
  }

//  @PostMapping("/users")
//  public User addUser(@RequestBody User user) {
//    return service.save(user);
//  }

  @PostMapping("/users")
  public ResponseEntity<Object> createUser(@Valid @RequestBody User user) {
    User createdUser = service.save(user);

    URI location = ServletUriComponentsBuilder
      .fromCurrentRequest()
      .path("/{id}")
      .buildAndExpand(createdUser.getId())
      .toUri();

    return ResponseEntity.created(location).build();
  }

  @DeleteMapping("/users/{id}")
  public void deleteUser(@PathVariable int id) {
    User user = service.deleteUser(id);
    if(user==null) {
      throw new UserNotFoundException("id-"+id);
    }
  }
}
