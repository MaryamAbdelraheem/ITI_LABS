package Data_Package;

public class City {

    private int id;
    private String name;
    private double population;
    private String countryCode;

    public City(int id, String name, double population, String countryCode) 
    {
        this.id = id;
        this.name = name;
        this.population = population;
        this.countryCode = countryCode;
    }

    public int getId() { return id; }
    public String getName() { return name; }
    public double getPopulation() { return population; }
    public String getCountryCode() { return countryCode; }
}