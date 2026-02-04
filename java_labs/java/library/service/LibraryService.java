package library.service;

import library.model.Book;
import library.model.User;

public class LibraryService {
    public void borrowBook(User user, Book book){
        System.out.println(user.getName() + " borrowed the book: " + book.getTitle());
    }
}