package simpletodolist;

import org.junit.jupiter.api.Test;

import java.lang.reflect.Field;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class AppTest {

    @SuppressWarnings("unchecked")
    private List<Task> getInternalList(Task.TaskList taskList) throws Exception {
        for (Field f : taskList.getClass().getDeclaredFields()) {
            if (List.class.isAssignableFrom(f.getType())) {
                f.setAccessible(true);
                return (List<Task>) f.get(taskList);
            }
        }
        throw new NoSuchFieldException("No List field found in Task.TaskList");
    }



    
    @Test
    void testMarkTaskAsDone() throws Exception {
        Task.TaskList taskList = new Task.TaskList();
        taskList.addTask("Test Task 2");
        List<Task> internal = getInternalList(taskList);
        int taskId = internal.get(0).getId();
        boolean result = taskList.markTaskAsDone(taskId);
        assertTrue(result);
        internal = getInternalList(taskList);
        assertTrue(internal.get(0).isDone());
    }

   


}
