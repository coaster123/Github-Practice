
package recursionlab;

public class TriangleNumberCalculator {

    public int value(int n) {
        if (n <= 0) {
            return 0;
        }
        return n + value(n - 1);


        
    }


    public int add(int n, int m) {

        int a = value(n);
        int b = value(m);

        return a + b;
    }




    public int subtract(int n, int m) {

        int a = value(n);
        int b = value(m);

        return a - b;
    }
}