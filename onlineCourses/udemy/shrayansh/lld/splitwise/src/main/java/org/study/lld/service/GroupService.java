package org.study.lld.service;

import org.study.lld.model.Group;
import org.study.lld.model.User;
import org.study.lld.model.expense.Expense;
import org.study.lld.util.CommonUtil;

import java.util.HashMap;
import java.util.Map;

public class GroupService {
    Map<String, Group> groupRepository = new HashMap<String, Group>();

    public Group addGroup(String name) {
        Group group = new Group(CommonUtil.generateRandomId(), name);
        groupRepository.put(group.getId(), group);
        return group;
    }

    public void addGroupUser(Group group, User user) {
        group.addUser(user);
    }

    public void addGroupExpense(Group group, Expense expense) {
        group.addExpense(expense);
    }

    public void displayBalanceSheet(Group group) {
        Map<User, Map<User, Double>> balanceSheet = group.getBalanceSheet();
        for (Map.Entry<User, Map<User, Double>> entry : balanceSheet.entrySet()) {
            System.out.println("User " + entry.getKey().getName() + " :");
            System.out.println(entry.getValue());
        }
    }

}
