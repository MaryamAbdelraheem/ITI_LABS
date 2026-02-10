package reader;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class CSVUtils {

    public static <T> List<T> read(String filePath, CSVMapper<T> mapper) {

        List<T> result = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {

            String line;

            // skip header
            br.readLine();

            while ((line = br.readLine()) != null) {
                String[] row = line.split(",");
                T obj = mapper.map(row); //
                result.add(obj);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

        return result;
    }
}
