package dishes;

public class DishStack {

    private Dish[] data;
    private int size;



    public DishStack(int capacity) {
        data = new Dish[capacity];
        size = 0;
    }



    public void push(Dish d) {
        if (size == data.length) {
            System.out.println("Stack is full");
            return;
        }


        data[size] = d;
        size++;


    }


    
    public Dish pop() {

        if (size == 0) {

            System.out.println("Stack is empty");
            return null;
        }

        size--;
        return data[size];
    }

    public Dish peek() {

        if (size == 0) {
            System.out.println("Stack is empty");
            return null;
        }

        return data[size - 1];

    }




    public int size() {
        return size;
    }



    
}
