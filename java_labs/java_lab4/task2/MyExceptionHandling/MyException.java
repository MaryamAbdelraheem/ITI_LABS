/*• Create your own exception class.
• Write down two other classes:
• the first will contain three methods throwing your newly
created exception class
• the second class will be calling the methods that throws
exception using the try-catch-finally block*/

//own exception class
package MyExceptionHandling;

public class MyException extends Exception {
    public MyException(String message) {
        super(message);
    }
}