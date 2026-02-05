/*Develop an application to convert temperature from Celsius to Fahrenheit using Function<T,R> using
inner classes
public class TempMain{

    public static void main(String[] args) {
        float x=24;
        float out= new Function<Float, Float> () {      
            @Override
            public Float apply (Float t) {
                return t * 2; // Example transformation: double the input value
            }
        }.apply(t:x);
    }
}*/

package InnerClassFunction;

import java.util.function.Function;
public class celsius_to_fahrenheit{

    // Inner class that implements Function to convert Celsius to Fahrenheit
    public class CelsiusToFahrenheitConverter implements Function<Double, Double> {
        @Override
        public Double apply(Double celsius) {
            return (celsius * 9 / 5) + 32;
        }
    }

    
}
