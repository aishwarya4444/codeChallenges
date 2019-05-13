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
import java.util.Optional;

@RestController
public class UserResourceJPA {

  @Autowired
  private UserRepository userRepository;

  @Autowired
  private PostRepository postRepository;

  @GetMapping("/jpa/users")
  public List<User> retrieveAllUsers() {
    return userRepository.findAll();
  }

  @GetMapping("/jpa/users/{id}")
  public Resource<User> retrieveUser(@PathVariable int id) {
    Optional<User> user = userRepository.findById(id);
    if(!user.isPresent()) {
      throw new UserNotFoundException("id-"+id);
    }
    Resource<User> resource = new Resource<User>(user.get());
    ControllerLinkBuilder linkTo = linkTo(methodOn(this.getClass()).retrieveAllUsers());
    resource.add(linkTo.withRel("all-users"));
    return resource;
  }

//  @PostMapping("/jpa/users")
//  public User addUser(@RequestBody User user) {
//    return service.save(user);
//  }

  @PostMapping("/jpa/users")
  public ResponseEntity<Object> createUser(@Valid @RequestBody User user) {
    User createdUser = userRepository.save(user);

    URI location = ServletUriComponentsBuilder
      .fromCurrentRequest()
      .path("/{id}")
      .buildAndExpand(createdUser.getId())
      .toUri();

    return ResponseEntity.created(location).build();
  }

  @DeleteMapping("/jpa/users/{id}")
  public void deleteUser(@PathVariable int id) {
    userRepository.deleteById(id);
  }

  @GetMapping("/jpa/users/{id}/posts")
  public List<Post> getUserPosts(@PathVariable int id) {
    Optional<User> user = userRepository.findById(id);
    if(!user.isPresent()) {
      throw new UserNotFoundException("id-"+id);
    }
    return user.get().getPosts();
  }

  @PostMapping("/jpa/users/{id}/posts")
  public ResponseEntity<Object> createPost(@PathVariable int id, @RequestBody Post post) {
    Optional<User> userOptional = userRepository.findById(id);
    if(!userOptional.isPresent()) {
      throw new UserNotFoundException("id-"+id);
    }
    User user = userOptional.get();
    post.setUser(user);
    postRepository.save(post);

    URI location = ServletUriComponentsBuilder
      .fromCurrentRequest()
      .path("/{id}")
      .buildAndExpand(post.getId())
      .toUri();
    return ResponseEntity.created(location).build();
  }
}
