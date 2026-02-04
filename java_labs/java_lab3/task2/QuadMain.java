import Package.QudraticTemp;

public class QuadMain {
    public static void main(String[] args) {
        // Real roots case
        Float[] realCoefficients = {1f, 3f, 2f}; // x^2 - 3x + 2 //
        Float[] realRoots = new QudraticTemp().apply(realCoefficients);
        System.out.println("=== Real Roots ===");
        for (Float r : realRoots) {
            System.out.println(r);
        }

        // Complex roots case
        Float[] complexCoefficients = {1f, 2f, 5f}; // x^2 + 2x + 5
        Float[] complexRoots = new QudraticTemp().apply(complexCoefficients);
        System.out.println("\n=== Complex Roots ===");
        for (Float r : complexRoots) {
            System.out.println(r);
        }
    }
}