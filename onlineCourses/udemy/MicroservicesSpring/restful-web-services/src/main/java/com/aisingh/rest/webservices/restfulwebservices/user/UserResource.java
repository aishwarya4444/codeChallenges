package com.aisingh.rest.webservices.restfulwebservices.user;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.support.ServletUriComponentsBuilder;
import org.springframework.hateoas.EntityModel;
import org.springframework.hateoas.server.mvc.WebMvcLinkBuilder;
import static org.springframework.hateoas.server.mvc.WebMvcLinkBuilder.*;

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
  public EntityModel<User> retrieveUser(@PathVariable int id) {
    User user = service.findOne(id);
    if(user==null) {
      throw new UserNotFoundException("id-"+id);
    }
    EntityModel<User> model = new EntityModel<>(user);
    WebMvcLinkBuilder linkTo = linkTo(methodOn(this.getClass()).retrieveAllUsers());
    model.add(linkTo.withRel("all-users"));

    return model;
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