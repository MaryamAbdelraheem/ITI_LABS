package reader;

public interface CSVMapper<T>{
    T map(String[] row);
}