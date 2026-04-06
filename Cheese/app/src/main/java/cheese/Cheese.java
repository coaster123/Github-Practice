package cheese;

import java.io.*;
import java.util.*;

public class Cheese {

    int pasteurized = 0;
    int raw = 0;
    int organicMoist = 0;

    HashMap<String, Integer> milk = new HashMap<>();

    public void start() {

        BufferedReader br = null;
        PrintWriter pw = null;

        try {

            br = new BufferedReader(new FileReader("cheese_data.csv"));
            pw = new PrintWriter("output.txt");

            String line = br.readLine();

            while ((line = br.readLine()) != null) {

                ArrayList<String> list = new ArrayList<>();

                String temp = "";
                boolean quote = false;

                for (int i = 0; i < line.length(); i++) {

                    char c = line.charAt(i);

                    if (c == '"') {
                        quote = !quote;
                    } else if (c == ',' && quote == false) {
                        list.add(temp);
                        temp = "";
                    } else {
                        temp = temp + c;
                    }
                }

                list.add(temp);

                if (list.size() > 9) {

                    String milkType = list.get(8);
                    String treatment = list.get(9);

                    if (treatment.equalsIgnoreCase("pasteurized")) {
                        pasteurized++;
                    } else if (treatment.equalsIgnoreCase("raw milk")) {
                        raw++;
                    }

                    try {

                        double m = Double.parseDouble(list.get(3));
                        int o = Integer.parseInt(list.get(6));

                        if (o == 1 && m > 41.0) {
                            organicMoist++;
                        }

                    } catch (Exception e) {
                    }

                    if (!milkType.equals("")) {

                        if (milk.containsKey(milkType)) {
                            milk.put(milkType, milk.get(milkType) + 1);
                        } else {
                            milk.put(milkType, 1);
                        }
                    }
                }
            }

            String most = "";
            int max = 0;

            for (String k : milk.keySet()) {

                if (milk.get(k) > max) {
                    max = milk.get(k);
                    most = k;
                }
            }

            pw.println("Pasteurized Milk Cheeses: " + pasteurized);
            pw.println("Raw Milk Cheeses: " + raw);
            pw.println("Organic Cheeses with >41% Moisture: " + organicMoist);
            pw.println("Most Common Milk Type: " + most);

        } catch (Exception e) {
            System.out.println("error");
        }

        try {
            if (br != null)
                br.close();
            if (pw != null)
                pw.close();
        } catch (Exception e) {
        }
    }
}