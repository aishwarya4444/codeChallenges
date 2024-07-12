package org.study.lld.service;

import org.study.lld.model.User;
import org.study.lld.util.CommonUtil;

import java.util.HashMap;
import java.util.Map;

public class UserService {
    Map<String, User> userRepository = new HashMap<String, User>();
    Map<String, User> userNameRepository = new HashMap<>();

    public User addUser(String name) {
        User user = User.builder()
                        .name(name)
                        .id(CommonUtil.generateRandomId())
                        .build();

        userRepository.put(user.getId(), user);
        userNameRepository.put(user.getName(), user);
    }

    public User getUserByName(String userName) {
        return userNameRepository.get(userName);
    }
}
