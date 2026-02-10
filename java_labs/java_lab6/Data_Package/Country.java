package Data_Package;

public class Country {

    private String code;
    private String name;
    private String continent;
    private double surfaceArea;
    private double population;
    private double gnp;
    private int capital; 

    public Country(String code, String name, String continent,
                   double surfaceArea, double population,
                   double gnp, int capital) 
    {
        this.code = code;
        this.name = name;
        this.continent = continent;
        this.surfaceArea = surfaceArea;
        this.population = population;
        this.gnp = gnp;
        this.capital = capital;
    }

    public double getSurfaceArea() { return surfaceArea; }
    public double getGnp() { return gnp; }
    public String getCode() { return code; }
    public String getName() { return name; }
    public String getContinent() { return continent; }
    public double getPopulation() { return population; }
    public int getCapital() { return capital; }
}