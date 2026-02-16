package simpletodolist;

import java.util.ArrayList;
import java.util.List;

public class Task {

    private static int nextId = 1;
    private int id;
    private String description;
    private boolean done;

    public Task(String description) {
        this.id = nextId++;
        this.description = description;
        this.done = false;
    }



    
    public int getId() {
        return id;
    }

    
    public String getDescription() {
        return description;
    }

    public boolean isDone() {
        return done;
    }

    public void setDone() {
        done = true;
    }

    @Override
    public String toString() {
        return "Task #" + id + ": " + description + (done ? " [Completed]" : " [Pending]");
    }


    
    public static class TaskList {

        private List<Task> taskList = new ArrayList<>();

        public void addTask(String description) {
            if (description == null || description.trim().isEmpty()) {
                System.out.println("Task description is empty!");
                return;
            }
            Task newTask = new Task(description);
            taskList.add(newTask);
        }


        
        public boolean markTaskAsDone(int id) {
            for (Task task : taskList) {
                if (task.getId() == id && !task.isDone()) {
                    task.setDone();
                    return true;
                }
            }
            return false;
        }

        
        public void displayTasks() {
            System.out.println("Completed Tasks:");
            for (Task task : taskList) {
                if (task.isDone()) {
                    System.out.println(task);
                }
            }

            
            System.out.println("\nPending Tasks:");
            for (Task task : taskList) {
                if (!task.isDone()) {
                    System.out.println(task);
                }
            }

            
        }

        public void clearAllTasks() {
            taskList.clear();
        }


        
    }
    
    

}
