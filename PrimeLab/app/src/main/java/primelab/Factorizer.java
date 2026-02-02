package primelab;

import java.util.ArrayList;
import java.util.List;

public class Factorizer {

    public ArrayList<Integer> primeFactors(int num) {
        ArrayList<Integer> factors = new ArrayList<>();
        if (num < 2) {
            return factors; 
        }
        for (int i = 2; i <= num; i++) {
            while (num % i == 0) {
                factors.add(i);
                num /= i;
            }
        }
        return factors;
    }
}
