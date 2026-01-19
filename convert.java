import java.util.Scanner;



public class convert{
    public static void main(String[] args){

        Scanner scan = new Scanner(System.in);
        System.out.println("Welcome to the Ounce Converter!");

        System.out.print("\n\nHow many ounces do you have -> ");
        int oz = scan.nextInt();

        Converter(oz);


        



    }


    public static void Converter(int n){

        int rem;
        int div;

        if(n<16){

            System.out.print("\n\nThis is only " + n + " ounces");

        }

        else{

            div = n/16;
            rem = n%16;


            System.out.print("\n\nThis amount is " + div + " pounds and " + rem + " ounces!");
            
        }

    }







}
