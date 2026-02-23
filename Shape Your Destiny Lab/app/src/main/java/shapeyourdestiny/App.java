
package shapeyourdestiny;

public class App {

    public static void main(String[] args) {



        Circle c = new Circle(5.0);
        System.out.println("Circle area -> " + c.getArea());
        System.out.println("Circle perimeter -> " + c.getPerimeter());

        System.out.println("\n\n");



        Rectangle r = new Rectangle(8.0, 4.0);
        System.out.println("Rectangle area -> " + r.getArea());
        System.out.println("Rectangle perimeter -> " + r.getPerimeter());
        System.out.println("Rectangle sides -> " + r.numberOfSides());


        System.out.println("\n\n");

        RightTriangle t = new RightTriangle(6.0, 8.0);
        System.out.println("Right triangle area -> " + t.getArea());
        System.out.println("Right triangle perimeter -> " + t.getPerimeter());
        System.out.println("Right triangle sides -> " + t.numberOfSides());


        System.out.println("\n\n");



        Square s = new Square(3.0);
        System.out.println("Square area -> " + s.getArea());
        System.out.println("Square perimeter -> " + s.getPerimeter());
        System.out.println("Square sides -> " + s.numberOfSides());

        
        System.out.println("\n\n");



        IsocelesRightTriangle i = new IsocelesRightTriangle(4.0);
        System.out.println("Isoceles right triangle area -> " + i.getArea());
        System.out.println("Isoceles right triangle perimeter -> " + i.getPerimeter());
        System.out.println("Isoceles right triangle sides -> " + i.numberOfSides());
    }
}