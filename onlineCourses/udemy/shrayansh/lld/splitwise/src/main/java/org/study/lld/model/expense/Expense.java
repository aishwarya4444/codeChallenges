package org.study.lld.model.expense;

import lombok.Getter;
import org.study.lld.model.Split;
import org.study.lld.model.User;

import java.time.LocalDateTime;
import java.util.List;

@Getter
public abstract class Expense {
    private int id;
    private String title;
    private User paidBy;
    private Double amount;
    private List<User> users;
    private List<Split> splits;
    private LocalDateTime createdAt;

    public Expense(int id, String title, User paidBy, Double amount, List<User> users, List<Split> splits, LocalDateTime createdAt) {
        this.id = id;
        this.title = title;
        this.paidBy = paidBy;
        this.amount = amount;
        this.users = users;
        this.splits = splits;
        this.createdAt = createdAt;
    }
}
