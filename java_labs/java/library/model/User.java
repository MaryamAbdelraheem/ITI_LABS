
package library.model;

public class user{
    private String name;
    private final int userId;

    public User(String name, int userId){
        this.name = name;
        this.userId = userId;
    }

    public String getName(){
        return name;
    }
}