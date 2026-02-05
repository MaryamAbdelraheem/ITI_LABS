package Complex_Package;

public class MyComplex implements Complex<Double> {
//double > float // implm generic .
    private Double real;
    private Double imag;

    public MyComplex(Double real, Double imag) {
        this.real = real;
        this.imag = imag;
    }

    @Override
    public Double getReal() {
        return real;
    }

    @Override
    public Double getImaginary() {
        return imag;
    }

    @Override
    public Complex<Double> add(Complex<Double> other) {
        return new MyComplex(
                real + other.getReal(),
                imag + other.getImaginary()
        );
    }

    @Override
    public Complex<Double> subtract(Complex<Double> other) {
        return new MyComplex(
                real - other.getReal(),
                imag - other.getImaginary()
        );
    }

    @Override
    public Complex<Double> multiply(Complex<Double> other) {
        double a = real;
        double b = imag;
        double c = other.getReal();
        double d = other.getImaginary();

        return new MyComplex(
                a * c - b * d,
                a * d + b * c
        );
    }

    @Override
    public Complex<Double> divide(Complex<Double> other) {
        double a = real;
        double b = imag;
        double c = other.getReal();
        double d = other.getImaginary();

        double denominator = c * c + d * d;

        return new MyComplex(
                (a * c + b * d) / denominator,
                (b * c - a * d) / denominator
        );
    }

    @Override
    public String toString() {
        return "(" + real + " + " + imag + "i)";
    }
}