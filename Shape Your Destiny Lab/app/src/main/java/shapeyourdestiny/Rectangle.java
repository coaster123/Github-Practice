package shapeyourdestiny;

public class Rectangle extends Shape implements Polygon {

    protected double l;
    protected double w;

    public Rectangle(double l, double w) {
        this.l = l;
        this.w = w;
    }

    public double getArea() {
        return l * w;
    }

    public double getPerimeter() {
        return 2 * (l + w);
    }

    public int numberOfSides() {
        return 4;
    }
    
}
