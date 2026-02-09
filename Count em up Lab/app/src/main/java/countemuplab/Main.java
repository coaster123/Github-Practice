package countemuplab;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        
        GroceryCounter counter = new GroceryCounter();
        Scanner scanner = new Scanner(System.in);
        boolean running = true;

        while (running) {

            System.out.println("Type: \nT for $10 dollars, \nS for $1, \nD for Dimes  \nP for Pennies \nE to quit \nChoice -> ");
            String choice = scanner.next();

            if (choice.equals("T") || choice.equals("t")) {
                counter.addTens();
            }
            else if (choice.equals("S") || choice.equals("s")) {
                counter.addOnes();
            }
            else if (choice.equals("D") || choice.equals("d")) {
                counter.addTenths();
            }
            else if (choice.equals("P") || choice.equals("p")) {
                counter.addHundredths();
            }
            else if (choice.equals("E") || choice.equals("e")) {
                running = false;
            }
            else {
                System.out.println("Please choose a valid option!");
            }

            if (running) {
                System.out.println("Current price: $" + counter.getPrice());
                System.out.println("Current amount of overflows: " + counter.getOverflows());
            }
        }
        System.out.println("Final price: $" + counter.getPrice());
        System.out.println("Total overflows: " + counter.getOverflows());
        scanner.close();
        
    }
}
