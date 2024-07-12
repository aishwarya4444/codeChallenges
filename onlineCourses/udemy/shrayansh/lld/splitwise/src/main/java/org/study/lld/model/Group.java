package org.study.lld.model;

import lombok.Getter;
import org.study.lld.model.expense.Expense;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@Getter
public class Group {
    String id;
    String name;
    List<User> users;
    List<Expense> expenses;
    Map<User, Map<User, Double>> balanceSheet;

    public Group(String id, String name) {
        this.id = id;
        this.name = name;
        this.users = new ArrayList<User>();
        this.expenses = new ArrayList<>();
        this.balanceSheet = new HashMap<User, Map<User, Double>>();
    }

    public void addUser(User user) {
        if (balanceSheet.containsKey(user)) {
            return;
        }

        balanceSheet.put(user, new HashMap<>());
        users.add(user);

        for(User friend: balanceSheet.keySet()) {
            balanceSheet.get(user).putIfAbsent(friend, 0.0);
            balanceSheet.get(friend).putIfAbsent(user, 0.0);
        }
    }

    public void addExpense(Expense expense) {
        User paidBy = expense.getPaidBy();

        for(Split split: expense.getSplits()) {
            User paidFor = split.getUser();
            Double amount = split.getAmount();
            if (!paidBy.equals(paidFor)) {
                Double share = balanceSheet.get(paidBy).get(paidFor);
                balanceSheet.get(paidBy).put(paidFor, amount + share);

                share = balanceSheet.get(paidFor).get(paidBy);
                balanceSheet.get(paidFor).put(paidFor, amount - share);
            }
        }
    }
}
