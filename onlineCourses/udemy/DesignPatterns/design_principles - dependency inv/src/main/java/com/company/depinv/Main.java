package com.company.depinv;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {

	public static void main(String[] args) throws IOException {
		
		Message msg = new Message("This is a new message");
		MessagePrinter printer = new MessagePrinter();
		printer.writeMessage(msg, new JSONFormatter(), new PrintWriter(new FileWriter("test_msg.txt")));
		printer.writeMessage(msg, new JSONFormatter(), new PrintWriter(System.out));
	}

}
