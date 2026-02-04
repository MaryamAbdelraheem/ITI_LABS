import Package.TemperatureConvert;


public class TempMain {
    public static void main(String[] args) {
        float x=24;
        System.out.println("Temp is = "+x+"C or "+
        new TemperatureConvert().apply(x)+" F");
    }
}