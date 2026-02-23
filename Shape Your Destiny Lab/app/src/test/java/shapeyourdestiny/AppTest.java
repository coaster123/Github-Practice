
package shapeyourdestiny;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class AppTest {
   
    @Test
    void testCircle() {
        Circle c = new Circle(7.0);
        assertEquals(153.94, c.getArea(), 0.01);
        assertEquals(43.98, c.getPerimeter(), 0.01);
    }



    @Test
    void testRectangle() {
        Rectangle r = new Rectangle(10.0, 3.0);
        assertEquals(30.0, r.getArea(), 0.01);
        assertEquals(26.0, r.getPerimeter(), 0.01);
        assertEquals(4, r.numberOfSides());
    }


    
    @Test
    void testRightTriangle() {
        RightTriangle t = new RightTriangle(9.0, 12.0);
        assertEquals(54.0, t.getArea(), 0.01);
        assertEquals(36.0, t.getPerimeter(), 0.01);
        assertEquals(3, t.numberOfSides());
    }

    @Test
    void testSquare() {
        Square s = new Square(4.0);
        assertEquals(16.0, s.getArea(), 0.01);
        assertEquals(16.0, s.getPerimeter(), 0.01);
        assertEquals(4, s.numberOfSides());
    }



    @Test
    void testIso() {
        IsocelesRightTriangle i = new IsocelesRightTriangle(8.0);
        assertEquals(32.0, i.getArea(), 0.01);
        assertEquals(27.31, i.getPerimeter(), 0.01);
        assertEquals(3, i.numberOfSides());
    }
    



    

}
