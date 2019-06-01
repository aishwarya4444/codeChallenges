package com.coffeepoweredcrew.simplefactory;

public class Client {

	public static void main(String[] args) {
		Post post = PostFactory.createPost("blog");
		System.out.println(post);
		
		post = PostFactory.createPost("news");
		System.out.println(post);
		
		post = PostFactory.createPost("product");
		System.out.println(post);
		
		post = PostFactory.createPost("my post");
		System.out.println(post);
	}

}
