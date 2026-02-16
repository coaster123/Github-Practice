package simpletodolist;

import org.junit.jupiter.api.Test;

import java.lang.reflect.Field;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class AppTest {

    @SuppressWarnings("unchecked")
    private List<Task> getInternalList(Task.TaskList taskList) throws Exception {
        Field field = Task.TaskList.class.getDeclaredField("taskList");
        field.setAccessible(true);
        return (List<Task>) field.get(taskList);
    }

    @Test
    void testAddTask() throws Exception {
        Task.TaskList taskList = new Task.TaskList();
        taskList.addTask("Test Task 1");
        List<Task> internal = getInternalList(taskList);
        assertEquals(1, internal.size());
        assertEquals("Test Task 1", internal.get(0).getDescription());
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

    @Test
    void testMarkTaskAsDoneInvalidId() {
        Task.TaskList taskList = new Task.TaskList();
        boolean result = taskList.markTaskAsDone(999);
        assertFalse(result);
    }

}