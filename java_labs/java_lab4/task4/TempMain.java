/**
 * Create a generic interface that could be used to represent
complex numbers
• Create some generic methods that represent basic arithmetic
operation on complex.
 */

import Complex_Package.Complex;
import Complex_Package.MyComplex;

public class TempMain {
    public static void main(String[] args) {
        Complex<Double> z1 = new MyComplex(3.0, 2.0);
        Complex<Double> z2 = new MyComplex(1.0, 7.0);

        Complex<Double> sum = z1.add(z2);
        Complex<Double> difference = z1.subtract(z2);
        Complex<Double> product = z1.multiply(z2);
        Complex<Double> quotient = z1.divide(z2);

        System.out.println("z1: " + z1.getReal() + " + " + z1.getImaginary() + "i");
        System.out.println("z2: " + z2.getReal() + " + " + z2.getImaginary() + "i");
        System.out.println("Sum: " + sum.getReal() + " + " + sum.getImaginary() + "i");
        System.out.println("Difference: " + difference.getReal() + " + " + difference.getImaginary() + "i");
        System.out.println("Product: " + product.getReal() + " + " + product.getImaginary() + "i");
        System.out.println("Quotient: " + quotient.getReal() + " + " + quotient.getImaginary() + "i");
    }
}