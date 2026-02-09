package countemuplab;

public class GroceryCounter {


    
    private int totalValue;
    private int overflowAmount;



    public GroceryCounter() {
        totalValue = 0;
        overflowAmount = 0;
    }



    public void addTens() {
        totalValue = totalValue + 1000;
        checkOverflow();
    }



    public void addOnes() {
        totalValue = totalValue + 100;
        checkOverflow();
    }

    public void addTenths() {
        totalValue = totalValue + 10;
        checkOverflow();
    }


    public void addHundredths() {
        totalValue = totalValue + 1;
        checkOverflow();
    }



    private void checkOverflow() {
        if (totalValue >= 10000) {
            totalValue = totalValue - 10000;
            overflowAmount = overflowAmount + 1;
        }
    }


    public void clear() {
        totalValue = 0;
        overflowAmount = 0;
    }

    public double getPrice() {
        return totalValue / 100.0;
    }

    public int getOverflows() {
        return overflowAmount;
    }


    
}

