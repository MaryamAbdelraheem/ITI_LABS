import Data_Package.City;
import Data_Package.Country;
import reader.CSVUtils;
import reader.CSVMapper;
import java.util.*;
import java.util.stream.Collectors;


public class Main {

    public static void main(String[] args) {
        
        List<Country> countries = CSVUtils.read(
         "csv_data/Countries.csv",
            row -> new Country(
            row[0].trim(),                            
            row[1].trim(),                            
            row[2].trim(),                            
            Double.parseDouble(row[3]),        
            Double.parseDouble(row[6]),        
            Double.parseDouble(row[5]),        
            (int) Double.parseDouble(row[4])   
         )
        );

        List<City> cities = CSVUtils.read(
        "csv_data/Cities.csv",
        row -> new City(
        (int) Double.parseDouble(row[0]),  
        row[1].trim(),                            
        Double.parseDouble(row[2]),        
        row[3].trim()                             
        )
        );
        
        Map<String, Optional<City>> highestCityPerCountry = 
        cities.stream()
          .collect(Collectors.groupingBy(
              City::getCountryCode,
              Collectors.maxBy(Comparator.comparingDouble(City::getPopulation))
          ));

        System.out.println("=== Highest Populated City per Country ===");
        countries.forEach(country -> {
        Optional<City> cityOpt = highestCityPerCountry.getOrDefault(country.getCode(), Optional.empty());
    
        cityOpt.ifPresent(city ->
        System.out.println(country.getName() + " -> " + city.getName() +
                           " | Population: " + city.getPopulation())
            );
        });
System.out.println("\n===---------------------------------------------------===");
        Map<String, Optional<Country>> mostPopulatedCountryPerContinent = 
        countries.stream()
          .collect(Collectors.groupingBy(
              Country::getContinent,
              Collectors.maxBy(Comparator.comparingDouble(Country::getPopulation))
          ));
        System.out.println("\n=== Most Populated Country per Continent ===");
        mostPopulatedCountryPerContinent.forEach((continent, countryOpt) -> {
        countryOpt.ifPresent(country -> 
        System.out.println(continent + " -> " + country.getName() +
                           " | Population: " + country.getPopulation())
            );
        });
System.out.println("\n===---------------------------------------------------===");
        Map<Integer, City> cityById = 
        cities.stream()
            .collect(Collectors.toMap(City::getId, city -> city));

        City highestCapital = countries.stream()
                .map(country -> cityById.get(country.getCapital()))  
                .filter(Objects::nonNull)                          
                .max(Comparator.comparingDouble(City::getPopulation)) 
                .orElse(null);                                     

        System.out.println("\n=== Highest Populated Capital City ===");
        if (highestCapital != null) {
        System.out.println(highestCapital.getName() + " | Population: " + highestCapital.getPopulation());
        } else {
        System.out.println("No capital cities found.");
        }


/*System.out.println("=== All Countries ===");
        for (Country c : countries) {
            System.out.println(
                "Name: " + c.getName() +
                " | Continent: " + c.getContinent() +
                " | Population: " + c.getPopulation() +
                " | Capital City ID: " + c.getCapital() +
                " | SurfaceArea: " + c.getSurfaceArea() +
                " | GNP: " + c.getGnp()
            );
        }

        System.out.println("\n=== All Cities ===");
        for (City c : cities) {
            System.out.println(
                "Name: " + c.getName() +
                " | CountryCode: " + c.getCountryCode() +
                " | Population: " + c.getPopulation()
            );
        }
*/

    }
}


