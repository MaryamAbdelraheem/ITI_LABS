/*Create a test class that defines a method that accepts a list
that contains only child classes of shape

Test your method by creating two ArrayList of Rectangle and
shapes and pass them to the generic method
*/
package Test;

import BaseShape.Shape;
import Rectangle.Rectangle;
import Circle.Circle;
import java.util.List;


public class TestClass{
    // Non-generic method (works only for List<Shape>)
    public void renderShapes(List<Shape> shapes){
        for (Shape shape : shapes){
            shape.draw();
        }
    }

    // Generic method (works for any subclass of Shape)
    public <T extends Shape> void renderShapesGeneric(List<T> shapes){
        for (T shape : shapes){
            shape.draw();
        }
    }
}
