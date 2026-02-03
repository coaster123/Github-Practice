
package org.example.app;

import java.util.Scanner;

public class App {

    public int getInput() {

        Scanner scanner = new Scanner(System.in);
        int num = 0;
        boolean flag = false;


        while (!flag) {
            System.out.print("Enter a number between 1 and 69: ");

            if (scanner.hasNextInt()) {
                num = scanner.nextInt();

                if (num >= 1 && num <= 69) {
                    flag = true;
                } 
                
                else {
                    System.out.println("Number is out of range.");
                }
            } 
            
            else {
                System.out.println("That is not a number.");
                scanner.next(); 
            }
        }

        return num;
    }

    public static void main(String[] args) {

        App app = new App();
        int value = app.getInput();

        System.out.println("You entered: " + value);
        
    }
}