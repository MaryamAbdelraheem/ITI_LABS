

import InnerClassFunction.celsius_to_fahrenheit;

public class TempMain{
    public static void main(String[] args) {
        celsius_to_fahrenheit converter = new celsius_to_fahrenheit();
        celsius_to_fahrenheit.CelsiusToFahrenheitConverter converterInstance = converter.new CelsiusToFahrenheitConverter();

        double celsius = 24.0;
        double fahrenheit = converterInstance.apply(celsius);
        System.out.println(celsius + " degrees Celsius is equal to " + fahrenheit + " degrees Fahrenheit.");
    }
}