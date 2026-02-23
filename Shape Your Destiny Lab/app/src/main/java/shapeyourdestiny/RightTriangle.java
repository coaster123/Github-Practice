package shapeyourdestiny;

public class RightTriangle extends Shape implements Polygon {
    
    private double length;
    private double width;

    public RightTriangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    public double getArea() {
        return 0.5 * (length * width);
    }

    public double getPerimeter() {
        return length + width + Math.hypot(length,width);
    }

    public int numberOfSides() {
        return 3;
    }


}
