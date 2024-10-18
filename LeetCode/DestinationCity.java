/* Logic:
Divide cities to starting and end cities.
Return the name of end city that is not part of the starting cities. 
HashSet stores only unique values. */

import java.util.Scanner;
import java.util.HashSet;

class Solution {

    public Scanner scan = new Scanner(System.in);

    public String destCity(List<List<String>> paths) {
        List<String> startingCities = new ArrayList<String>();
        List<String> endingCities = new ArrayList<String>();

        for (List<String> pairOfCities : paths) {
            startingCities.add(pairOfCities.get(0));
            endingCities.add(pairOfCities.get(1));
        }

        endingCities.removeAll(startingCities);

        return endingCities.get(0);
    }
}