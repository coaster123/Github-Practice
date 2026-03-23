
package visual.studios.code;

import java.util.ArrayList;

public class Search {

  ArrayList<Fuzzy> fuzzies;

  public Search(ArrayList<Fuzzy> fuzzies) {
    this.fuzzies = fuzzies;
  }

  public int linearSearch() {
    for (int i = 0; i < fuzzies.size(); i++) {
      if (fuzzies.get(i).color.equals("gold")) {
        return i;
      }
    }
    return -1;
  }

  public int binarySearch() {
    int low = 0;
    int high = fuzzies.size() - 1;

    while (low <= high) {
      int mid = (low + high) / 2;

      String color = fuzzies.get(mid).color;

      if (color.equals("gold")) {
        return mid;
      }

      if (color.compareTo("gold") < 0) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return -1;
  }
}
