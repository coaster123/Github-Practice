package countemuplab;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class GroceryCounterTest {

    

    @Test
    void testAddTens() {
        GroceryCounter counter = new GroceryCounter();
        counter.addTens();
        assertEquals(10.00, counter.getPrice());
    }


    
    @Test
    void testAddOnes() {
        GroceryCounter counter = new GroceryCounter();
        counter.addOnes();
        assertEquals(1.00, counter.getPrice());
    }

    
    @Test
    void testAddTenths() {
        GroceryCounter counter = new GroceryCounter();
        counter.addTenths();
        assertEquals(0.10, counter.getPrice());
    }

    @Test
    void testAddHundredths() {
        GroceryCounter counter = new GroceryCounter();
        counter.addHundredths();
        assertEquals(0.01, counter.getPrice());
    }


    
    @Test
    void testOverflowCounter() {
        GroceryCounter counter = new GroceryCounter();

        for (int i = 0; i < 30; i++) {
            counter.addTens();
        }

        assertEquals(3, counter.getOverflows());
    }


}
