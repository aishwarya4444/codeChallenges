package org.study.lld.util;

import java.util.UUID;

public class CommonUtil {

    public static String generateRandomId() {
        return UUID.randomUUID().toString();
    }
}
