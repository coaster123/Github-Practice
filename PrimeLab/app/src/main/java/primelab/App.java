
package primelab;

import java.util.List;
import java.util.Scanner;

public class App {
    
public static void main(String[] args) {
    
    Factorizer factorizer = new Factorizer();
    Scanner scanner = new Scanner(System.in);
        
    System.out.print("Please input a number that is greatr than or equl to 2 ->  ");

    if (scanner.hasNextInt() && scanner.nextInt() >= 2) {
        int number = scanner.nextInt();
        System.out.println(factorizer.primeFactors(number));
    }   
    else {
        System.out.println("Please put in a correct value next time!");
    }


    
    }
}
