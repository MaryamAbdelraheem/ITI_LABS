import Circle.Circle;
import Rectangle.Rectangle;
import BaseShape.Shape;
import Test.TestClass;
import java.util.ArrayList;
import java.util.List;

public class TempMain {
    public static void main(String[] args) {
        TestClass tester = new TestClass();

        // ArrayList of Shape
        List<Shape> shapesList = new ArrayList<>();
        shapesList.add(new Rectangle());
        shapesList.add(new Circle());

        // ArrayList of Rectangle
        List<Rectangle> rectangleList = new ArrayList<>();
        rectangleList.add(new Rectangle());
        rectangleList.add(new Rectangle());

        // Non-generic method
        System.out.println("Using renderShapes:");
        tester.renderShapes(shapesList);  // works
        // tester.renderShapes(rectangleList); //  error! 

        // Generic method
        System.out.println("\nUsing renderShapesGeneric:");
        tester.renderShapesGeneric(shapesList);
        tester.renderShapesGeneric(rectangleList);
    }
}