package MyExceptionThrower;
import MyExceptionHandling.MyException;


public class customExeception {
    public void methodOne(double value) throws MyException {
        if (value < 0){
            throw new MyException("Value cannot be negative(methodOne)");
        }
        System.out.println("Value is: " + value);
    }

    public void methodTwo(String text) throws MyException {
        if(text == null || text.isEmpty()){
            throw new MyException("Text cannot be null or empty(methodTwo)");
        }
        System.out.println("Text is: " + text);
    }

    public void methodThree(int a, int b) throws MyException {
        if (b == 0) {
            throw new MyException("Division by zero is not allowed (methodThree).");
        }
        System.out.println("Division result is: " + (double) a / b);
    }
}