package library.util;

public class IdGenerato {
    private static int currentId = 100;
    
    public static int generatorId() {
        return currentId++;
    }
}