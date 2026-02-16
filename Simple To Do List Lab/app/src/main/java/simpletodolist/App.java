
package simpletodolist;

import java.util.Scanner;

public class App {

    public static void main(String[] args) {

        
        Scanner scan = new Scanner(System.in);
        Task.TaskList tasks = new Task.TaskList();
        boolean flag = true;

        while (flag) {

            
            System.out.println("\nMenu:");
            System.out.println("1. Add a Task");
            System.out.println("2. Mark Task as Done");
            System.out.println("3. Show All Tasks");
            System.out.println("4. Delete All Tasks");
            System.out.println("5. Quit");
            System.out.print("Choose an option (1-5) ->  ");



            
            int choice = scan.nextInt();
            scan.nextLine();
            
            if (choice == 1) {
                System.out.print("Enter the task you want to add -> ");
                String taskDescription = scan.nextLine();
                tasks.addTask(taskDescription);
                System.out.println("Task has been added.");
                
            } 
            
            else if (choice == 2) {
                System.out.print("Enter which task ID to mark as done -> ");
                int taskId = scan.nextInt();
                scan.nextLine();
                boolean result = tasks.markTaskAsDone(taskId);
                if (result) {
                    System.out.println("Task marked as done.");
                } 
                else {
                    System.out.println("Task not found or already done.");
                }

            } 
            
            
            else if (choice == 3) {
                tasks.displayTasks();

            } 
            else if (choice == 4) {
                tasks.clearAllTasks();
                System.out.println("All tasks deleted.");

            } 
            else if (choice == 5) {
                flag = false;

            } 
            else {
                System.out.println("Invalid option. Please pick between 1 and 5.");
            }
        }


        
        scan.close();
    }
}
