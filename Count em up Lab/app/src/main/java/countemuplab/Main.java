package countemuplab;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        
        GroceryCounter counter = new GroceryCounter();
        
        
        Scanner scanner = new Scanner(System.in);
        boolean flag = true;

        
        while (flag) {


            System.out.println("Type: \nT for $10 dollars, \nS for $1, \nD for Dimes  \nP for Pennies \nE to quit \nC for Clear Counter\nChoice -> ");
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
                flag = false;
            }
            else if (choice.equals("C") || choice.equals("c")) {
                counter.clear();
            }
            else {
                System.out.println("Please choose a valid option!");
            }


            if (flag) {
                System.out.println("Current price: $" + counter.getPrice());
                System.out.println("Current amount of overflows: " + counter.getOverflows());
            }


        }

        System.out.println("Final price: $" + counter.getPrice());
        System.out.println("Total overflows: " + counter.getOverflows());
        scanner.close();
    }

    
}



