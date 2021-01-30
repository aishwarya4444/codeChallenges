package com.infiniteskills.data;

import org.hibernate.Session;

public class Application {
    public static void main(String[] args) {
        Session session = HibernateUtil.getSessionFactory().openSession();
        session.beginTransaction();
        session.close();
    }
}
