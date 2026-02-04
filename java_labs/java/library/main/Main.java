package library.main;

import library.model.Book;
import library.model.User;
import library.service.LibraryService;
import library.util.IdGenerator;

public class Main {

    public static void main(String[] args) {

        Book book = new Book(
                "Clean Code",
                "Robert Martin",
                2008,
                "B" + IdGenerator.generateId()
        );

        User user = new User("Maryam", IdGenerator.generateId());

        LibraryService service = new LibraryService();
        service.borrowBook(user, book);
    }
}