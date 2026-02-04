package library.model;

public class Book {
    private String Title;          // private → accessed via getter
    protected String Author;       // protected → accessible in subclasses
    int year;                      // default → same package only
    public final String ISBAN;     // public + final → accessible everywhere, constant

    public Book(String title, String author, int year, String isban) {
        this.Title = title;
        this.Author = author;
        this.year = year;
        this.ISBAN = isban;
    }
    public String getTitle() {
        return Title;
    }
}

    
                    
     