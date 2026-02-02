package primelab;

import org.junit.jupiter.api.Test;
import java.util.ArrayList;
import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class FactorizerTest {

    @Test
    void testOdd() {
        Factorizer factorizer = new Factorizer();
        assertEquals(factorizer.primeFactors(15), new ArrayList<>(Arrays.asList(3, 5)));
    }

    @Test
    void testEven() {
        Factorizer factorizer = new Factorizer();
        assertEquals(factorizer.primeFactors(20), new ArrayList<>(Arrays.asList(2, 2, 5)));
    }

    @Test
    void testHundred() {
        Factorizer factorizer = new Factorizer();
        assertEquals(factorizer.primeFactors(100), new ArrayList<>(Arrays.asList(2, 2, 5, 5)));
    }

}


